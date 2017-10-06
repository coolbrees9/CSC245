//Colin O'Neal
//Project 2
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include"stack.h"
#include<string>
#include <cctype>
#include <fstream>
#include <cstdlib>
using namespace std;

void printStack(const Stack<int> &s);
bool stringIsDigit(string cmd);
int size(const Stack<int> &s);
void program(Stack<int> &t, string cmd);
void takeInput(Stack<int> &t, string cmd);

int main(int argc, char* argv[])
{
	Stack<int> t;
	string cmd;
	cout << "Starting Postfix Calculator..." << endl;
	//cin >> cmd;
	while(getline(cin, cmd))
	{
		takeInput(t, cmd);
	}
	return 0;
}

//Method takes your input and determines how to handle it
void takeInput(Stack<int> &t, string cmd)
{
	int i;
	int temp;
	try
	{
		for( i = 0; i < cmd.length(); i++)
		{
			if(isspace(cmd[i]))
			{}
			else if(cmd[i] == '_' && isdigit(cmd[i+1]))
			{
				temp = cmd[i+1] - '0';
				temp *= -1;
				t.push(temp);
			}
			else if(cmd[i-1] != '_' && isdigit(cmd[i]))
			{
				temp = cmd[i] - '0';
				int count = 1;
				while(isdigit(cmd[i + count]))
				{
					temp = temp *10 + cmd[i + count] - '0';
					count++;
				}
				i = i + count - 1;
				t.push(temp);
			}
			else
			{
    				int x, y;
    					if(cmd[i] == 'p')
					{
    					if(!t.isEmpty())
    					{
    						cout << t.top();
    						cout << endl;
    					}
    					}
    		
    					else if(cmd[i] == 'n')
					{
    					if(!t.isEmpty())
    					{
    						cout << t.top();
    						t.pop();
    					}
    					}
    
    					else if(cmd[i] == 'f')
					{
    					if(!t.isEmpty())
    					{
    					printStack(t);
    					}
    					}
    
    					else if(cmd[i] == 'c')
					{
    					if(!t.isEmpty())
    						t.makeEmpty();
    					}
    
    					else if(cmd[i] == 'd')
					{
    					if(!t.isEmpty())
    						t.push(t.top());
    					}
    
    					else if(cmd[i] == 'r')
					{
    					if(!t.isEmpty())
    					{
    						x = t.topAndPop();
            					y = t.topAndPop();
            					t.push(x);
            					t.push(y);
    					}
    					}
    
    					else if(cmd[i] == '+')
					{
    					if(!t.isEmpty() && size(t) > 1)
                    			{
                            			x = t.topAndPop();
                            			y = t.topAndPop();
                            			t.push(x + y);
                    			}
                    			else
                            			cout << "Not enough integers" << endl;
                    			}
    
    					else if(cmd[i] == '-')
					{
    					if(!t.isEmpty() && size(t) > 1)
                    			{
                            			x = t.topAndPop();
                            			y = t.topAndPop();
                            			t.push(y - x);
                    			}
                    			else
                            			cout << "Not enough integers" << endl;
                    			}
    
    					else if(cmd[i] == '*')
					{
    					if(!t.isEmpty() && size(t) > 1)
    					{
                            			x = t.topAndPop();
                            			y = t.topAndPop();
                            			t.push(x * y);
                    			}
                    			else
                            			cout << "Not enough integers" << endl;
                    			}
    
    					else if(cmd[i] == '/')
					{
    					if(!t.isEmpty() && size(t) > 1)
    					{
    						x = t.topAndPop();
                    				y = t.topAndPop();
    						if(temp == 0)
    							throw DivisionByZero();
    						else
                    					t.push(y / x);
    					}
    					else
    						cout << "Not enough integers" << endl;
    					}
    
    					else if(cmd[i] == '%')
					{
    					if(!t.isEmpty() && size(t) > 1)
    					{
    						x = t.topAndPop();
                   	 			y = t.topAndPop();
                    				t.push(y % x);
    					}
    					else
    						cout << "Not enough integers" << endl;
    					}
					else if(cmd[i-1] == '_')
					{}
    
    					else
    						cout << "Not a valid command, try again." << endl;	
			}
		}
	}
    	catch(DivisionByZero exc)
    	{
    		cout << "Division by zero not allowed, try again" << endl;
    	}
    	catch(Underflow obj)
    	{
    		cout << "Can't pop an empty string" << endl;
    	}
    	catch(Overflow obj)
    	{
    		cout << "Stack is Full" << endl;
    	}
 }
//Prints the full Stack 
void printStack(const Stack<int> &s)
{
	Stack<int> temp = s;
	while(!temp.isEmpty())
		cout << temp.topAndPop() << endl;
}
//checks to see if input is an integer and returns true if it is
bool stringIsDigit(string cmd)
{
	for(int i = 0; i < cmd.length(); i++)
	{
		if(!isdigit(cmd[i]))
			return false;
	}
	return true;
}
//Calculates the size of the stack	
int size(const Stack<int> &s)
{
	int count = 0;
	Stack<int> temp = s;
	while(!temp.isEmpty())
	{
		count++;
		temp.pop();
	}
	return count;
}	
