

// This program uses hours, pay rate, state tax and fed tax to determine gross
// and net pay.

// Jerred Shepherd

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// Fill in the code to define payfile as an input file
	float gross;
	float net;
	float hours;
	float payRate;
    float stateTax;
	float fedTax;
	ifstream payroll;
	ofstream log;

	cout << fixed << setprecision(2) << showpoint;
	// FILL IN THE CODE TO OPEN payfile AND ATTACH IT TO THE PHYSICAL FILE
    // NAMED payroll.dat
	payroll.open("payroll.txt");
	log.open("pay.out");

	// FILL IN CODE TO WRITE A CONDITIONAL STATEMENT TO CHECK IF payfile 
	// DOES NOT EXIST.
	if (payroll.fail()) {
		log << "Error opening file. \n";
		log << "It may not exist where indicated" << endl;

		system("pause");

		return 1;

	}

	log << "Payrate      Hours    Gross Pay       Net Pay" 
           << endl   << endl;      
     // FILL IN CODE TO PRIME THE READ FOR THE payfile FILE.
	payroll >> hours;

     // FILL IN CODE TO WRITE A LOOP CONDITION TO RUN WHILE payfile HAS MORE 
     // DATA TO PROCESS.
	while (payroll) {
	   payroll >> payRate >> stateTax >> fedTax;
	   gross = payRate * hours;
	   net = gross - (gross * stateTax) - (gross * fedTax);
	   log << payRate << setw(15) << hours << setw(12) << gross
              << setw(12)  << net << endl;

	   // FILL IN THE CODE TO FINISH THIS WITH THE APPROPRIATE  
	   // VARIABLE TO BE INPUT

	   payroll >> hours;
	}

	payroll.close();
	
	system("pause");

}