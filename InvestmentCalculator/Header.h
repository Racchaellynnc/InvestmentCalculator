#pragma once
#pragma once
#ifndef DRIVER_H_
#define DRIVER_H_

class Source {
public:
	//Default Constructor
	Source();

	//This calls the menu options so they can be used
	int dataInputScreen();
	void investmentDataScreen();
	double getMoneyInput();
	int getNumberInput();

	// This calls the interest earned calculator
	void InterestCalculations(double InitialInvestment, double MonthlyDeposit, int Interest, int NumYears);

private:
	double InitialInvestment;
	double MonthlyDeposit;
	int Interest;
	int NumYears;

};

#endif