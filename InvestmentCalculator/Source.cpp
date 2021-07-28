#include <iostream>
#include <iomanip>
#include <cctype>
#include <stdexcept>
#include <vector>
#include <limits>
#include "Header.h"


using namespace std;

// This is the initial display menu that will show up.
int Source::dataInputScreen() {

	// This sets border on the top with 33 * 's
	cout << setw(33) << setfill('*') << "*" << endl;

	// This surrounds the title Data Input with 10 *'s on each side
	cout << setw(10) << setfill('*') << "*";
	cout << " Data Input ";
	cout << setw(11) << setfill('*') << "*" << endl;

	// This will expect the user to enter their Initial Investment Amount
	cout << setw(28) << setfill(' ') << left << "Initial investment amount:";
	InitialInvestment = getMoneyInput();
	cout << "$";
	cout << fixed << setprecision(2) << InitialInvestment << endl;

	// This will expect the user to enter their Monthly Deposit input
	cout << setw(28) << setfill(' ') << left << "Monthly deposit:";
	MonthlyDeposit = getMoneyInput();
	cout << "$";
	cout << fixed << setprecision(2) << MonthlyDeposit << endl;

	// This will expect the user to enter their Interest Percentage input
	cout << setw(32) << setfill(' ') << left << "Annual interest:";
	Interest = getNumberInput();
	cout << "%" << Interest << endl;

	// This will expect the user to enter their Investment Duration input
	cout << setw(32) << setfill(' ') << left << "Number of years:";
	NumYears = getNumberInput();
	cout << NumYears << endl;

	return 0;
}

void Source::investmentDataScreen() {

	// This is the screen that will show users their investment facts after the user inputs their data. 
	cout << "   Balance and Interest with Additional Monthly Deposits" << endl;
	cout << setw(60) << setfill('=') << "=" << endl;
	cout << "Year\t" << "    Year End Balance\t" << "    Year end Earned Interest" << endl;
	cout << setw(60) << setfill('-') << "=" << endl;

	// This is the calculation WITH monthly deposits.
	InterestCalculations(this->InitialInvestment, this->MonthlyDeposit, this->Interest, this->NumYears);

	cout << endl;
	cout << endl;

	cout << "   Balance and Interest without Additional Monthly Deposits" << endl;
	cout << setw(60) << setfill('=') << "=" << endl;
	cout << "Year\t" << "    Year End Balance\t" << "    Year end Earned Interest" << endl;
	cout << setw(60) << setfill('-') << "=" << endl;

	// This is the calculation WITHOUT monthly deposits.
	InterestCalculations(this->InitialInvestment, 0, this->Interest, this->NumYears);



}
void Source::InterestCalculations(double InitialInvestment, double MonthlyDeposit, int Interest, int NumYears) {
	int i;
	int j;
	int k;

	double newInvestmentAmount = InitialInvestment;
	double interest = Interest;
	double interestTotal = 0;
	const int NUM_MONTHS = 12;
	double compoundInterest;
	vector<double> interests;

	/*
	 * This for loop prints out the # of years, year end balance, and year end earned interest
	 * The second loop is set up to calculate the new balance after monthly deposit is added, '
	 * compounding interest on the new balance using the interest rate, and adding the compounding interest.
	 */
	for (i = 1; i <= NumYears; i++) {
		for (j = 1; j <= NUM_MONTHS; j++) {
			newInvestmentAmount = (newInvestmentAmount + MonthlyDeposit);
			compoundInterest = newInvestmentAmount * ((interest / 100) / NUM_MONTHS);
			newInvestmentAmount = newInvestmentAmount + compoundInterest;
			interests.push_back(compoundInterest);
		}
		// This adds up all interest payments
		for (k = 0; k < interests.size(); k++) {
			interestTotal = interests.at(k) + interestTotal;
		}

		// This is the output text to the user for the amount of interest they will accrue over time
		cout << i << "\t    $" << newInvestmentAmount << "\t\t     $" << interestTotal << endl;

		// This resets the values so you can start back at 0 if you want to run the Application again
		interestTotal = 0;
		compoundInterest = 0;
		interests.resize(0);
	}
}

double Source::getMoneyInput() {
	double userInput;
	cin >> userInput;

	/*
	 *  This checks if the user has entered a valid entry for getMoneyInput function.
	 *  If they have not, it tests for the correct error message
	 */
	while (!cin.good() || userInput < 0) {
		cout << endl;

		// This will show an error message if the user is not using integers for their input.
		if (!cin.good()) {
			cout << "ERROR: Invalid Entry. Please use numbers and try again: " << endl;
		}

		// This will show an error message if the using a negative number for their input.
		if (userInput < 0) {
			cout << "ERROR: Invalid Entry. Please use a positive number and try again" << endl;
		}

		// This clears anything thats in cin
		cin.clear();
		cin.ignore(LC_MAX, '\n');
		// This lets the user try again
		cin >> userInput;

	}
	return userInput;
}
int Source::getNumberInput() {
	int userInput;
	cin >> userInput;


	/*  This is doing the same thing as above, checking for errors.
	 *  This checks if the user has entered a valid entry for getNumberInput function.
	 *  If they have not, it tests for the correct error message
	 */
	while (!cin.good() || userInput < 0) {
		cout << endl;

		// This will show an error message if the user is not using integers for their input.
		if (!cin.good()) {
			cout << "ERROR: Invalid Entry. Please use numbers and try again: " << endl;
		}

		// This will show an error message if the using a negative number for their input.
		if (userInput < 0) {
			cout << "ERROR: Invalid Entry. Please use a positive number and try again" << endl;
		}

		// This clears anything thats in cin
		cin.clear();
		cin.ignore(LC_MAX, '\n');//this is the maximum double number you could possibly have.

		// This lets users start over again
		cin >> userInput;
	}

	return userInput;
}
Source::Source() {

}