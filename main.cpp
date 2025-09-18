#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string firstName, lastName;
    double baseSalary, commissionPercent;
    double totalSales, expenses;
    double commission, totalPay;

    string fileName;
    ifstream inFile;

    cout << "Enter the name of the input file: ";
    cin >> fileName;

    inFile.open(fileName.c_str());

    if (!inFile)
    {
        cout << "Error: Cannot open file." << endl;
        return 1;
    }

    inFile >> firstName >> lastName;
    inFile >> baseSalary >> commissionPercent;
    inFile >> totalSales;
    inFile >> expenses;

    inFile.close();

    commission = (commissionPercent / 100) * totalSales;
    totalPay = baseSalary + commission;   // expenses NOT subtracted

    cout << fixed << setprecision(2);
    cout << "\nPayroll data for " << firstName << " " << lastName << endl;
    cout << endl;

    cout << "Base Salary:" << setw(10) << baseSalary << endl;

    cout << "Commission:" << setw(10) << commission 
         << " (" << fixed << setprecision(1) << commissionPercent 
         << "% of " << setprecision(2) << totalSales << ")" << endl;

    cout << "Expenses:" << setw(12) << expenses << endl;
    cout << "---------" << endl;

    cout << "Total:" << setw(14) << totalPay << endl;

    return 0;
}
