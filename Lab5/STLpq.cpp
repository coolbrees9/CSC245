#include <queue>
#include <iostream>
#include <string>

using namespace std;
void insert(priority_queue<string> &names);
void printQueue(priority_queue<string> names);
int main()
{
	priority_queue<string> names;
	insert(names);
	printQueue(names);
	return 0;
}

void insert(priority_queue<string> &names)
{
	names.push("Colin");
	names.push("Matt");
	names.push("Josh");
	names.push("Avery");
	names.push("Stephen");
	names.push("Bob");
	names.push("Andy");
	names.push("David");
	names.push("Sarian");
	names.push("Johnny");
}

void printQueue(priority_queue<string> names)
{
	if(!names.empty())
	{
		while(!names.empty())
		{
			cout << names.top() << endl;
			names.pop();
		}
	}
	else
		cout << "Nothing in heap" << endl;
}
