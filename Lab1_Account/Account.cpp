#include "Account.h"

Bank::Bank()
{
    string name = "";
    int acno = 0;
    string actype = "";
    float balance = 0;
}

void Bank::init()
{
    std::cout << "New Account" << "\n";
    std::cout << "Enter the Name of the depositor :";
    std::cin >> name;
    std::cout << "Enter the Account Number :";
    std::cin >> acno;
    std::cout << "Enter the Account Type : (CURR / SAVG / FD / RD / DMAT) :";
    std::cin >> actype;
    std::cout << "Enter the Amount to Deposit :";
    std::cin >> balance;
}

void Bank::deposit()
{
    float add;
    std::cout << "Depositing" <<"\n";
    std::cout << "Enter the amount to deposit :";
    std::cin >> add;
    balance += add;
}

void Bank::withdraw()
{
    float sub;
    std::cout << "Withdrwal" <<"\n";
    std::cout << "Enter the amount to withdraw :";
    std::cin >> sub;
    balance -= sub;   
}

void Bank::disp_det()
{
    std::cout << "Account Details" << "\n";
    std::cout << "Name of the depositor :" << name << "\n";
    std::cout << "Account Number        :" << acno << "\n";
    std::cout << "Account Type          :" << actype << "\n";
    std::cout << "Balance               : $" << balance << "\n";
}