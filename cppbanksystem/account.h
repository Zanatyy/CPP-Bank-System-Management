//
// Created by Zanaty on 9/26/2021.
//
#ifndef BANKK_ACCOUNT_H
#define BANKK_ACCOUNT_H
enum accountype{NOT_DEFINED=0,Saving=1, Salary=2, Fixed_Deposit=3}; //bank account types.
class account{
private:
    int accnum;
    char firstname[10];
    char lastname[10];
    char fullname[20];
    double total_balance;
public:
    account(){};
    account(int,char*,char*,float);
    void setter();	//function to get data from user
    void show_account();	//function to show data on screen
    void modify();	//function to add new data
    void dep(int);	//function to accept amount and add to balance amount
    void draw(int);	//function to accept amount and subtract from balance amount
    void report();	//function to show data in tabular format
    int retacno();	//function to return account number
    double retdeposit();	//function to return balance amount
    accountype rettype();	//function to return type of account
    void setat(accountype);
    accountype at=NOT_DEFINED;
};
#endif //BANKK_ACCOUNT_H
