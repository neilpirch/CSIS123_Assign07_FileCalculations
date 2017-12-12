// Assign07-FileCalculations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string empName;
	int compScore, effScore, creatScore, safeScore, courtScore, totalScore;
	double aveScore;
	int recordCnt = 0;
	int runningTotal = 0;
	double aveTotal;

	ifstream performance;

	performance.open("Performance.txt");

	if (!performance)
	{
		cout << endl << "Error opening input file" << endl << endl;
		system("pause");
		return-1;
	}

	cout << fixed << setprecision(1);
	cout << "Employee       Avg" << endl;
	cout << "------------   ---" << endl;

	performance >> empName;

	while (!performance.eof())
	{
		performance >> compScore >> effScore >> creatScore >> safeScore >> courtScore;

		recordCnt++;
		totalScore = compScore + effScore + creatScore + safeScore + courtScore;
		aveScore = (static_cast<double>(totalScore) / 5);
		runningTotal += totalScore;

		cout << left << setw(12) << empName << right << setw(6) << aveScore << endl;

		performance >> empName;
	}

	performance.close();

	aveTotal = (static_cast<double>(runningTotal) / (recordCnt * 5));
	cout << endl << "Overall avg:" << right << setw(6) << aveTotal;	
	
	cout << endl << endl << endl;
	system("pause");
	return 0;
}

