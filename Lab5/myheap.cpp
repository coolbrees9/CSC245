#include <stdio.h>
#include <iostream>
#include "BinaryHeap.h"
using namespace std;

int main()
{
	BinaryHeap<char> PQ(50);
	for(char letters = 'A'; letters <= 'J'; letters++)
	{
		PQ.insert(letters);
	}
	//PQ.PrintLeaves();
	PQ.deleteMin();

	cout << "Printing Left Subtree: ";
	PQ.printLtSubtree();
	cout << endl;

	cout << "The height is: " << PQ.Height() << endl;

	cout << "The max value in the heap is: " << PQ.findMax() << endl;

	PQ.PrintLeaves();
	cout << endl;

return 0;
}
