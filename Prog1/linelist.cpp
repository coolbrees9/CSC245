#include<iostream>
#include "linelist.h"
using namespace std;
LineList::LineList()
{
	LineNode *line = new LineNode;
	LineNode *line2 = new LineNode;

	line -> info = topMessage;
	currLine = line;
	currLineNum = 0;
	length = 0;
	line2 -> info = bottomMessage;
	currLine -> back = NULL;
	currLine -> next = line2;
	line2 -> back = line;
	line2 -> next = NULL;
}
//Takes the current line to the top
void LineList::goToTop() 
{
	// Post : Advances currLine to line 1
	while(currLine -> info != topMessage)
		currLine = currLine -> back;
	currLine = currLine -> next;
	currLineNum = 1;
}
//Takes the current line to the bottom
void LineList::goToBottom() 
{
	// Post : Advances currLine to last line
	while(currLine -> info != bottomMessage)
		currLine = currLine -> next;
	currLine = currLine -> back;
	currLineNum = length;
}
//Inserts a new line after the current line
void LineList::insertLine(string newLine)
{
	// post : newLine has been inserted after the current line
	if(currLine -> info == bottomMessage)
	{
		currLine = currLine -> back;
		currLineNum--;
	}
	LineNode *insert = new LineNode;
	insert -> info = newLine;
	insert -> back = currLine;
	currLine -> next -> back = insert;
	insert -> next = currLine -> next;
	currLine -> next = insert;
	currLine = insert;
	length++;
	currLineNum++;
}
//Deletes the current line 
void LineList::deleteLine()
{
	// post : deletes the current line leaving currentLine
	//	  pointing to line following
	if((currLine -> info != topMessage) && (currLine -> info != bottomMessage))
	{
		LineNode *dlt = new LineNode;
		currLine -> back -> next = currLine -> next;
		currLine -> next -> back = currLine -> back;
		dlt = currLine;
		if(currLine -> next -> info != bottomMessage)
		{
			currLine = currLine -> next;
			currLineNum++;
		}
		else
		{
			currLine = currLine -> back;
			currLineNum--;
		}

		delete dlt;
		length--;
	}
}
//Prints the whole list
void LineList::printList() 
{
	int lineNum = 1;
	LineNode *Mark = currLine;
	int markNum = currLineNum;
	goToTop();
	LineNode *curr = currLine;
	while(curr -> info != bottomMessage)
	{
		cout << lineNum << "> " << curr -> info << endl;
		curr = curr -> next;
		lineNum++;
	}
	currLine = Mark;
	currLineNum = markNum;
}
//Returns the current line user is on
string LineList::getCurrLine() const
{
	
	return currLine -> info;
}
//Changes the current line to the next line
void LineList::moveNextLine()
{
	// Post : Advances currLine (unless already at last line)
	if((currLine -> info != bottomMessage) && (currLine -> next != NULL))
	{
		currLine = currLine -> next;
		currLineNum++;
	}
}
//Changes the current line to the previous line
void LineList::movePrevLine()
{
	// Post : Advances currLine (unless already at last line)
	if((currLine -> back != NULL) && (currLine -> info != topMessage))
	{
		currLine = currLine -> back;
		currLineNum--;
	}
	cout << currLineNum << "> ";
}
//Returns the current Line number the user is on
int LineList::getCurrLineNum() const
{
	return currLineNum;
}
//Returns the current length of the list
int LineList::getLength() const
{
	return length;
}
