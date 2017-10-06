//Colin O'Neal
//radix.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;
int maxElemLength(const vector<int>& v);
int GetDigit(int number, int k);
vector<queue<int> > ItemsToQueues(const vector<int>& L, int k);
vector<int> QueuesToArray(vector<queue<int> >& QA, int numVals);
void RadixSort(vector<int>& L, int numDigits);
void PrintVector(const vector<int>& L);

int main()
{
	int arr[] = {380, 95, 345, 382, 260, 100, 492};
	vector<int> L;
	vector<queue<int> > QA(10);
	L.insert(L.begin(), arr, arr+7);
	cout << "Before Radix Sort" << endl;
	for(int i = 0; i < L.size(); i++)
		cout << L[i]<< endl;
	cout << "Next is Radix Sort" << endl;
	RadixSort(L, maxElemLength(L));
	PrintVector(L);
	return 0;
}

int maxElemLength(const vector<int>& v)
{
	if(!v.empty())
	{
		int max;
		int length = 0;
		for(int i = 0; i < v.size(); i++)
		{
			if(v[i] > v[i+1])
				max = v[i];
		}
		while(max > 0)
		{
			max /= 10;
			length++;
		}
		return length;
	}
	else
		return 0;
}

int GetDigit(int number, int k)
{
	int temp = k;
	if(k > number)
		return 0;
	else
	{
		for(int i = 0; i <= temp; i++)
		{
			k = number % 10;
			number /= 10;
		}
		return k;
	}
}

vector<queue<int> > ItemsToQueues(const vector<int>& L, int k)
{
	vector<queue<int> > QA(10);
	if(!L.empty())
	{
		for(int x = 0; x < L.size(); x++)
		{
			QA[GetDigit(L[x], k)].push(L[x]);
		}
	}
	return QA;
}

vector<int> QueuesToArray(vector<queue<int> >& QA, int numVals)
{
	vector<int> L;
	while(L.size() < numVals)
	{
		for(int i = 0; i < QA.size(); i++)
		{
		while(!QA[i].empty())
		{
			L.push_back(QA[i].front());
			QA[i].pop();
		}
		}
	}
	return L;
}

void RadixSort(vector<int>& L, int numDigits)
{
	for(int i = 0; i < numDigits; i++)
	{
		vector<queue<int> > test = ItemsToQueues(L, i);
		L = QueuesToArray(test, numDigits);
	}
}

void PrintVector(const vector<int>& L)
{
	vector<int> temp = L;
	for(int i = 0; i < temp.size(); i++)
	{
		cout << temp[i] << endl;
	}
}
