//Colin O'Neal
//radixS.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;
int maxElemLength(const vector<string>& v);
char GetLetter(string word, int k);
vector<queue<string> > ItemsToQueues(const vector<string>& L, int k);
vector<string> QueuesToArray(vector<queue<string> >& QA, int numVals);
void RadixSort(vector<string>& L, int numLetters);
void PrintVector(const vector<string>& L);
vector<string> padding(vector<string>& L, int numLetters);
vector<string> unpadding(vector<string>& L, int numLetters);

int main()
{
	string arr[] = {"zebra", "apple", "orange", "can", "candy", "a", "top", "pumpkin", "today", "parade"};
	vector<string> L;
	vector<queue<string> > QA(128);
	L.insert(L.begin(), arr, arr+10);
	cout << "Before sorting" << endl;
	for(int i = 0; i < L.size(); i++)
		cout << L[i] << " ";
	cout << endl;
	RadixSort(L, maxElemLength(L));
	cout << "After Radix Sort" << endl;
	//unpadding(L, maxElemLength(L));
	PrintVector(L);
	return 0;
}

int maxElemLength(const vector<string>& v)
{
	if(!v.empty())
	{
		string max;
		int length = 0;
		for(int i = 0; i < v.size()-1; i++)
		{
			if(v[i].length() > v[i+1].length())
				max = v[i];
		}
		length = max.length();
		return length;
	}
	else
		return 0;
}

char GetLetter(string word, int k)
{
	char letter;
	if(k > word.length())
		return 0;
	else
	{
		for(int i = 0; i <= k; i++)
		{
			letter = word[word.length() - 1 - k];
		}
		return letter;
	}
}

vector<queue<string> > ItemsToQueues(const vector<string>& L, int k)
{
	vector<queue<string> > QA(128);
	if(!L.empty())
	{
		for(int x = 0; x < L.size(); x++)
		{
			QA[GetLetter(L[x], k)].push(L[x]);
		}
	}
	return QA;
}

vector<string> QueuesToArray(vector<queue<string> >& QA, int numVals)
{
	vector<string> L;
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

void RadixSort(vector<string>& L, int numLetters)
{
	padding(L, maxElemLength(L));
	for(int i = 0; i < numLetters; i++)
	{
		vector<queue<string> > test = ItemsToQueues(L, i);
		L = QueuesToArray(test, numLetters);
	}
	unpadding(L, maxElemLength(L));
}

void PrintVector(const vector<string>& L)
{
	vector<string> temp = L;
	for(int i = 0; i < temp.size(); i++)
	{
		cout << temp[i] << " ";
	}
	cout << endl;
}

vector<string> padding(vector<string>& L, int numLetters)
{
	for(int i = 0; i < L.size(); i++)
	{
		while(L[i].length() != numLetters)
			L[i] += " ";
	}
	return L;
}

vector<string> unpadding(vector<string>& L, int numLetters)
{
	for(int i = 0; i < L.size(); i++)
	{
		while(L[i].at(L[i].length()-1) == ' ')
			L[i] = L[i].substr(0, L[i].length()-1);
	}
	return L;
}
