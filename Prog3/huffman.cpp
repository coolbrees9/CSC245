using namespace std;
#include "huffman.h"
#include <cctype>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <climits>

HuffmanTree:: HuffmanTree()
	: numChars(0), built(false) {}
//Inserts characters in the tree
void HuffmanTree:: insert(char ch, int weight) {
    HNode newNode = {ch, weight, 0, -1}; 
    built = false;
    nodes.push_back(newNode);
    numChars++;

}
//Checks if the value entered is in tree
bool HuffmanTree:: inTree(char ch) {
	return ch == lookUp(ch);

}
//public to get frequency of the character
int HuffmanTree:: GetFrequency(char ch) {
	return GetFrequency(ch);
}
//private and gets frequency of character
int HuffmanTree:: GetFrequency(int i) {
	char ch;
	int Letters[i];
	for (ch = char(0);  ch <= char(126);  ch++)
                Letters[ch] = 0;

        cin.get(ch);
        while (cin)
        {
                Letters[ch] += 1;
                cin.get(ch);
        }
	return ch;
}
//Returns index of where character is at
int HuffmanTree:: lookUp(char ch) {
	int pos = 0;
	while(pos < numChars)
	{
		if(nodes[pos].ch == ch)
			return pos;
		pos++;
	}
	return -1;
}
//public and returns compressed code of character
string HuffmanTree:: GetCode(char ch) {
	return GetCode(lookUp(ch));
}
//private and returns compressed code of character
string HuffmanTree:: GetCode(int i) {
	if (nodes[i].parent == 0)
          return "";
        else
          return (GetCode(nodes[i].parent) + (char)(nodes[i].childType+'0'));
}
//Prints the Encoding Table
void HuffmanTree:: PrintTable() {
	int a = 1;
	printf("\t++++  Encoding Table  ++++\n\n");
	printf("Index\tChar\tWeight\tParent\tChildType\n");
	for(int i = 0; i < numChars; i++)
          if (nodes[i].ch != ' ' && nodes[i].ch != '\0')
            cout << i <<"\t" << nodes[i].ch <<"\t" << nodes[i].weight <<"\t" << nodes[i].parent <<"\t" << nodes[i].childType << endl;
	  else if(nodes[i].ch == '\0' && nodes[i].childType != -1)
	  {
	    cout << i <<"\t" << 'T' <<a<<"\t" << nodes[i].weight <<"\t" << nodes[i].parent <<"\t" << nodes[i].childType << endl;
	    a++;
	  }
	  else
	  {
	    cout << i <<"\t" << 'T' <<a<<"\t" << nodes[i].weight <<"\t" << "0" <<"\t" << "-1" << endl;
	  }
}
//Returns the number of nodes in tree
int HuffmanTree:: numNodes(){
	return numChars;
}
//Build the huffman tree
void HuffmanTree:: build() {
	int max = (numChars*2) - 1;
	while(max > numChars)
	{
		int smallest;
		int min1;
		smallest = INT_MAX;
		for(int i = 0; i < numChars; i++)
		{
			if(nodes[i].parent == 0 && nodes[i].weight < smallest)
			{
				min1 = i;
				smallest = nodes[i].weight;
			}
		}
		int min2;
		smallest = INT_MAX;
		for(int j = 0; j < numChars; j++)
		{
			if((nodes[j].parent == 0) && (nodes[j].weight < smallest) && (j != min1))
			{
				min2 = j;
				smallest = nodes[j].weight;
			}
		}
		HNode temp = {'\0',(nodes[min1].weight + nodes[min2].weight),0,-1};
		nodes.push_back(temp);
		nodes[min1].parent = nodes.size() - 1;
		nodes[min1].childType = 0;
		nodes[min2].parent = nodes.size() - 1;
		nodes[min2].childType = 1;
		numChars++;
	}
	nodes[nodes.size() - 1].parent = 0;
	built = true;
}
