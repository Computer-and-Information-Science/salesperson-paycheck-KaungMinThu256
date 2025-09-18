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

    string fileName;
    cout << "Enter the name of the input file: ";
    cin >> fileName;

    ifstream inFile(fileName.c_str());
    if (!inFile)
    {
        cout << "Error: could not open file " << fileName << endl;
        return 1;
    }

    
    inFile >> firstName >> lastName;
    inFile >> baseSalary >> commissionPercent;
    inFile >> totalSales;
    inFile >> expenses;

    inFile.close();

    
    double commission = (commissionPercent / 100.0) * totalSales;
    double totalPay = baseSalary + commission - expenses;

    
    cout << fixed << setprecision(2);
    cout << "\nPayroll data for " << firstName << " " << lastName << "\n\n";

    cout << "Base Salary:" << setw(10) << baseSalary << endl;

    cout << "Commission:" << setw(10) << commission 
         << " (" << setprecision(1) << commissionPercent << "% of " 
         << setprecision(2) << totalSales << ")" << endl;

    cout << "Expenses:"   << setw(12) << expenses << endl;
    cout << "             --------" << endl;
    cout << "Total:"      << setw(13) << totalPay << endl;

    return 0;
}
