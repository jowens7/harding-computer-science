//proof of concept based on the line format
#include<string>
#include<iostream>
using namespace std;

void main()
{
	string exampleText = "Php 2:14 I Paul urge you to...";

	string newText = exampleText.substr(4);
	size_t pos = newText.find(" ");
	cout << newText.substr(0, pos) << endl;

}