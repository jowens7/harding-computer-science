#include <fstream>
#include <iostream>
using namespace std;

// Jerred Shepherd

const int MAXNAME = 20;

int main()
{
	ifstream inData;
	inData.open("grades.txt");

	char name[MAXNAME + 1];  // holds student name
	float average;  // holds student average


	inData.get(name,MAXNAME+1);
	while (inData)
	{
		inData >> average;
		// FILL IN THE CODE to print out name and 
		// student average
		cout << name;
		cout << "has a(n) " << average << "average" << endl;

		// FILL IN THE CODE to complete the while 
		// loop so that the rest of the student
		// names and average are read in properly
		inData.get(name, MAXNAME + 1);
	}

	system("pause");

	return 0;

}