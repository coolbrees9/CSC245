//Colin ONeal
//zip.cpp
#include <cctype>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include "huffman.h"

using namespace std;
void Frequency(ifstream& infile, int Letters[], int argc, char *argv[], int source, string& S);
void PrintLetters (const int Letters[], HuffmanTree& htree, int header);
void Compress(ifstream& infile, int argc, char *argv[], int Letters[256], HuffmanTree& htree, int source, string& S, int header);
int main(int argc, char *argv[])
{
	string S;
	int source = 0;
	int header = 0;
	int Letters[256];
	string input;
	if(argc > 1)
		input = argv[1];
	HuffmanTree htree;
        ifstream infile;
	if(argc <= 1)
	{
		cout << "Error!! No File Entered." << endl;
		exit(1);
	}
	else if(input.compare("--help") == 0)
	{
		infile.open("help");
		string in;
		while(!infile.eof())
		{
			getline(infile, in);
			cout << in << endl;
		}
		exit(1);
	}
	else
	{
		Frequency(infile, Letters, argc, argv, source, S);
		PrintLetters(Letters, htree, header);
		htree.build();
        	Compress(infile, argc, argv, Letters, htree, source, S, header);
	}

        return 0;
}
//Opens the file entered after the a.out and compresses it 
void Compress(ifstream& infile, int argc, char *argv[], int Letters[256], HuffmanTree& htree, int source, string& S, int header)
{
	int compressed = 0;
	float ratio;
	int i, j;
	string input = argv[1];
	string filename;
	if(argc > 2)
		filename = argv[2];
	else
		filename = argv[1];
	infile.open(filename.c_str());
	//Checks if file entered is valid or not
	if(infile.fail())
	{
		cout << "Must enter a filename" << endl;
		exit(1);
	}
	else
	{
		header = htree.numNodes() - (htree.numNodes()/2);
		//Adds .zip to the file
		filename+=".zip";
		ofstream outfile;
                outfile.open(filename.c_str());
		outfile << header << endl;
		//Loop to compress each char
		for (char ch = char(0);  ch <= char(126);  ch++)
		{
	  		if ( (Letters[ch] != 0) && (ch != '\n') && (ch != ' ') )
			{
	    			outfile << (int)ch << " " << htree.GetCode(ch) << endl;
				source++;
			}
	  		else if ( (Letters[ch] != 0) && (ch == '\n') )
			{
	    			outfile << (int)ch << " "<< htree.GetCode('^') << endl;
				source++;
			}
	  		else if ( (Letters[ch] != 0) && (ch == ' ') )
			{
	    			outfile << (int)ch << " " << htree.GetCode('$') << endl;
				source++;
			}
		}
		//Prints Encoding table if --t is entered
		if(input.compare("--t") == 0 && argc > 2)
        	{
        		htree.PrintTable();
        	}
		char code;
		for(int i = 0; i < S.length(); i++)
		{
			code = S[i];
			outfile << htree.GetCode(code);
			compressed++;
		}
		outfile << endl;
		outfile.close();
		ratio = (1 -(float)(compressed/((float)source*8))) * 100;
		cout << "File Successfully Compressed to " << compressed << " Bits (" << ratio << "% Less)" << endl;
	}
}
//Method to count weight
void Frequency (ifstream& infile, int Letters[], int argc, char* argv[], int source, string& S)
{
	string filename;
	char ch;
	if(argc > 2)
		filename = argv[2];
	else
		filename = argv[1];
	infile.open(filename.c_str());
	for (char ch = char(0);  ch <= char(126);  ch++)
		Letters[ch] = 0;

	infile.get(ch);
	while (infile)
	{
		Letters[ch] += 1;
		S+=ch;
		infile.get(ch);
	}
	infile.close();
}
//Method to insert chars into tree
void PrintLetters (const int Letters[], HuffmanTree& htree, int header)
{
	for (char ch = char(0);  ch <= char(126);  ch++)
	  	if ( (Letters[ch] != 0) && (ch != '\n') && (ch != ' ') )
		{
	    		htree.insert(ch, Letters[ch]);
			header++;
		}
		else if ( (Letters[ch] != 0) && (ch == '\n') )
		{
	    		htree.insert('^', Letters[ch]);
			header++;
		}
	  	else if ( (Letters[ch] != 0) && (ch == ' ') )
		{
	    		htree.insert('$', Letters[ch]);
			header++;
		}
}
