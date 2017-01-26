#include <iostream>
#include <iomanip>
using namespace std;


// This program uses a structure to hold data about a rectangle 
// Jerred Shepherd

// FILL IN CODE TO define a structure named rectangle which has 
// members length, width, area, and perimeter all of which are floats

struct Rectangle {
	float length, width, area, perimeter;
};

int main()
{
	Rectangle r;

    cout << "Enter the length of a rectangle: ";
	
	cin >> r.length;

	cout << "Enter the width of a rectangle: ";
	
	cin >> r.width;

	cout << endl << endl;

	r.area = r.length * r.width;
	r.perimeter = (r.length * 2) + (r.width * 2);

	cout << fixed << showpoint << setprecision(2);
	

	cout << "The area is " << r.area << endl;
	cout << "The perimeter is " << r.perimeter << endl;
	
	if (r.length == r.width)
		cout << "It is a square";
	else
		cout << "It is not a square";

	cout << endl << endl;

	system("pause");

	return 0;
}