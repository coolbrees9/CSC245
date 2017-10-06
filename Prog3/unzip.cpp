//Colin O'Neal
//unzip.cpp
using namespace std;
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <stdio.h>
#include <fstream>
#include <string>
#include "huffman.h"
#include <map>

void OpenFile (ifstream& infile, int argc, char *argv[]);
void fillMap(map<string, char>& M, ifstream& infile, string line, string code, string comp, char* argv[]);

int main(int argc, char *argv[])
{
	ifstream infile;
	string line;
	string code;
	string comp;
	map<string, char> M;
	OpenFile(infile, argc, argv);
	fillMap(M, infile, line, code, comp, argv);
	printf("File Successfully Inflated Back to Original.\n"); 

	return 0;
}
//Opens the file entered after the a.out
void OpenFile (ifstream& infile, int argc, char *argv[])
{
	if (argc == 1)
	{
		cout << "Error!! No File Entered." << endl;
		exit(1);
	}
	string filename = argv[1];
	infile.open(filename.c_str());
	string unzip = filename.substr(filename.find("."), 3);
	if(unzip.compare("zip") == 0)
	{
		cout << "Cannot unzip file, not zipped." << endl;
		exit(1);
	}
}
//Method that fills the map from file and converts back to normal
void fillMap(map<string, char>& M, ifstream& infile, string line, string code, string comp, char* argv[])
{
	int header, ascii;
	infile >> header;
	for(int i = 0; i < header; i++)
	{
		infile >> ascii >> code;
		M[code] = (char) ascii;
	}
 	//gets the line of long code
	infile >> comp;
	infile.close();
	ofstream outfile;
	string filename = argv[1];
	filename = filename.substr(0, filename.find("."));
	outfile.open(filename.c_str());
	string check;
	int pos = 0;
	int j = 1;
	//Loop that goes through long binary line
	for(int i = 0; i < comp.length(); i++)
	{
		check = comp.substr(pos,j);
		if(!(M.find(check) == M.end()))
		{
			outfile<< M.at(check);
			pos = i + 1;
			j = 1;
		}
		else
			j++;
	}
	outfile.close();
}
