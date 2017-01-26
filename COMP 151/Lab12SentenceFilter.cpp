//  Chapter 12, Programming Challenge 7: Sentence Filter

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cctype>
using namespace std;

bool processLine(ofstream &, char *, bool);

void openError(string fname) {
	cout << "Error opening " << fname << endl;
	exit(EXIT_FAILURE);
}

int main() {
	const int MAXLINE = 1001;
	ifstream inFile;	// Input file object
	ofstream outFile;	// Output file object
	string inName, outName;	// Input,Output file names
	char inputLine[MAXLINE];// most recently read line of input
	bool justSeenPeriod;	// true if we have not seen a letter since the
				// last period we encountered, otherwise false;
				// If it is true and we encounter a letter, the letter gets capitalized
				// If it is false and we encounter a letter, the letter is made lowercase
				// Set to true when we encounter period, set to false when a letter
				//	gets capitalized

	cout << "Enter the input file name: "; getline(cin, inName);
	cout << "Enter the output file name: "; getline(cin, outName);
	
	inFile.open(inName.c_str());	if (inFile.fail()) openError(inName);
	outFile.open(outName.c_str());	if (outFile.fail()) openError(outName);
	
	justSeenPeriod = true;	// pretend initially we have just seen a period so we start with a capital
	inFile.getline(inputLine, MAXLINE, '\n');
	while (!inFile.fail()) {
		justSeenPeriod = processLine(outFile, inputLine, justSeenPeriod);
		inFile.getline(inputLine, MAXLINE, '\n');
	}
	
	inFile.close();
	outFile.close();
	return 0;
}

bool processLine(ofstream &outFile, char *cp, bool justSeenPeriod) {
	while (*cp != 0) {
		char c = *cp++;
		if (isalpha(c)) {
			c = tolower(c);
			if (justSeenPeriod) {
				c=toupper(c);
				justSeenPeriod = false;
			}
		} else if (c=='.') justSeenPeriod = true;
		outFile.put(c);
	}
	outFile.put('\n');
	return justSeenPeriod;
}