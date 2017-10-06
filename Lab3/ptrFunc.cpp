//Colin O'Neal
//Lab3

#include<iostream>
#include<string>
using namespace std;

bool identical(double *ptr1, double *ptr2);
bool address(double *ptr1, double *ptr2);

int main()
{
	double num = 9.0;
	double num2 = 9.0;
	double *ptr1 = new double;
	double *ptr2 = new double;
	ptr1 = &num;
	ptr2 = &num2;
	if(identical(ptr1, ptr2))
		cout << "Identical" << endl;
	if(address(ptr1, ptr2))
		cout << "Address" << endl;

	return 0;
}

bool identical(double *ptr1, double *ptr2)
{
	return *ptr1 == *ptr2;
}

bool address(double *ptr1, double *ptr2)
{
	return ptr1 == ptr2;
}
