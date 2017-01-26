// This program will demonstrate finding text within a text file and
// displaying the line numbers where the text was found.

//This program will search a text file for sub-texts and if found,
//will output to a file "frequency.txt" the line numbers wherein
//the sub-text is found.

#include<fstream>
#include<iostream>
#include<string>

using namespace std;

void main()
{
	// declare input and output file stream objects
	ifstream fin;
	ofstream fout;

	// declare c++ strings to hold an input line, input file name, and text-to-find
	string fInputLine, fileName, textToFind;

	// declare a line counter and a text frequency counter
	int lineCount = 0, textFrequency = 0;

	// variable to store user response to continuation of searching for text
	char response;

}