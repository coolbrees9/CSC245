#include <iostream>
using namespace std;

double convert(double value);

int main()
{
	double value;
	cout << "Please enter a Celsius value: ";
	cin >> value;
	cout << value << " degrees Celsius is " << convert(value) 
	<< " degrees Fahrenheit." << endl;
	return 0;
}
//converts the given value into fahrenheit
double convert(double tmp)
{
	tmp = 1.8 * tmp + 32.0;
	return tmp;
}
