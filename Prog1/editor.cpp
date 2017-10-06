//Colin O'Neal
//Project 1

#include<iostream>
#include"linelist.h"
#include<string>
#include <cctype>
#include <fstream>
#include <cstdlib>
using namespace std;

void OpenFile(ifstream& infile, int argc, char *argv[]);
void makeList(ifstream& infile, LineList& l);
void Save(char *argv[], LineList& l);
int main(int argc, char* argv[])
{
	LineList l;
	ifstream infile;
        OpenFile(infile, argc, argv);
	makeList(infile, l);
	l.printList();
	cout << l.getCurrLineNum() << "> ";
	char cmd;
	int lineNum;
	string newLine;
		while(cmd != 'E')
		{
			cin >> cmd;
			switch(cmd)
			{
				case 'I':
				lineNum = l.getCurrLineNum()+1;

   				if (l.getCurrLineNum() > l.getLength())
       					lineNum--;

   				cout << lineNum << "> ";
   				getline (cin, newLine);
   				l.insertLine(newLine);
				break;

				case 'D':
				l.deleteLine();
				cout << l.getCurrLineNum() << "> ";
				break;

				case 'L':
				l.printList();
				cout << l.getCurrLineNum() << "> ";
				break;

				case 'P':
				l.movePrevLine();
				break;

				case 'N':
				l.moveNextLine();
				cout << l.getCurrLineNum() << "> ";
				break;
				
				case 'E':
				Save(argv, l);
				break;

				default:
					cout << "Command not found, please try again." << endl;
					cout << l.getCurrLineNum() << "> ";
			}
		}
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
}
//Makes a list from the testfile
void makeList(ifstream& infile, LineList& l)
{
	string line;
	while(getline(infile, line))
		l.insertLine(line);
	infile.close();
}
//Saves the program's list
void Save(char *argv[], LineList& l)
{
	ofstream outfile;
	string filename = argv[1];
	outfile.open(filename.c_str());
	l.goToTop();
	for(int i = 0; i < l.getLength(); i++)
	{
		outfile << l.getCurrLine() << endl;
		l.moveNextLine();
	}
	outfile.close();	
}
