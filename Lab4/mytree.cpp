//Colin O'Neal
//Lab4
#include<iostream>
#include "bst.h"
using namespace std;

int main()
{
	BinarySearchTree<int> T(0);

	T.insert(6);
	T.insert(8);
	T.insert(2);
	T.insert(1);
	T.insert(4);
	T.insert(3);

	T.printTree();
	cout << endl;
	T.postOrder();
	
	cout << "Height is: ";
	cout << T.height() << endl;
	cout << "# of Leaves: " <<  T.NumLeaves() << endl;
	if(T.isBalanced())
		cout << "It is Balanced!" << endl;
	else
		cout << "It's not Balanced!" << endl;
	
	T.insert(9);
	T.printTree();
	if(T.isBalanced())
                cout << "It is Balanced!" << endl;
        else
                cout << "It's not Balanced!" << endl;

	return 0;
}
