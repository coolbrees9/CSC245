//Colin O'Neal
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;
void Initialize(vector<int>& v);
void Print(vector<int>& v);
void Reverse(vector<int>& v);

int main()
{
	stack<string> s1, s2;
	s1.push("Hi there");
	s1.push("I am Colin");
	s1.push("How is your day");
	s2.push("My day is good");
	s2.push("I have to end now");
	if(s1==s2)
		cout << "s1==s2";
	else if(s1<s2)
		cout << "s1<s2";
	else
		cout << "s1>s2";
	cout << endl;

	vector<int> v;
	Initialize(v);
	Print(v);
	Reverse(v);
	Print(v);
	sort(v.begin(), v.end());
	Print(v);

	return 0;
}

void Initialize(vector<int>& v)
{
	int i = 0;
	int num;
	while(i < 5)
	{
		cout << "Enter value: ";
		cin >> num;
		v.push_back(num);
		i++;
	}
}

void Print(vector<int>& v)
{
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

void Reverse(vector<int>& v)
{
	reverse(v.begin(), v.end());
}
