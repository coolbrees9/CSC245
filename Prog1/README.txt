This program uses the specification file linelist.h and implementation file linelist.cpp. The implementation file contains the methods goToTop, goToBottom, insertLine, deleteLine, printList, moveNextLine, movePrevLine, getCurrLineNum, getLength, and getCurrLine.

goToTop method just moves your current line to the very top of the list.

goToBottom method moves your current line to the bottom of the list.

insertLine method simply inserts a new line after the current line.

deleteLine just deletes the current line and it moves to the next line.

printList prints out the entire list with all the line numbers included.

moveNextLine simply moves the current line to the next line.

movePrevLine simply move the current line to the previous line.

getCurrLineNum returns the value of the current line number.

getLength returns a number representing the length of the list.

getCurrLine returns the string of the whole currLine.

The client file will use these methods in order to allow the user to use a line editor which uses a doubly linked list in that the user can move easily around the list from top to bottom.

The OpenFile method in the client file is used to open a file after the a.out is entered and put it into the list.

The MakeList method is used to make a doubly linked list from the file that came from OpenFile.

The Save method saves the list's current state when E is entered, then exits.

The goal of the client file is to create an editor where a user can move throughout a doubly linked list and add and delete lines as they want.
