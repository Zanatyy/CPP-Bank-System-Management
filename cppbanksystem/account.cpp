//
// Created by Zanaty on 9/26/2021.
//
#include "account.h"
#include <iostream>
#include <string.h>
using namespace std;
void account::setter(){
    FILE *file;
    cout<<"Enter account number.\n";
    cin>>accnum;
    cout<<"Enter first name.\n";
    cin>>firstname;
    cout<<"Enter last name.\n";
    cin>>lastname;
    cout<<"Enter balance.\n";
    cin>>total_balance;
    strcpy(fullname,firstname);
    strcat(fullname," ");
    strcat(fullname,lastname);
    if(file=fopen("defaultdata.txt","a")) {
        fprintf(file,"%i %s %lf\n",accnum,fullname,total_balance);
    }
}
void account::show_account(){
    cout<<"Name: "<<fullname<<endl<<"Account number: "<<accnum<<endl<<"Balance: "<<total_balance<<endl;
}
void account::modify(){
    this->setter();
}
void account::dep(int i){
    total_balance=total_balance+i;
}
void account::draw(int i){
    if(total_balance<i){
        cout<<"Insuffucient fund to withdraw"<<endl;
        return;
    }
    total_balance=total_balance-i;
}
int account::retacno(){
    return accnum;
}

account::account(int i,char f[10],char l[10],float b){
    accnum=i;
    strcpy(firstname,f);strcpy(lastname,l);
    strcpy(fullname,firstname);
    strcat(fullname," ");
    strcat(fullname,lastname);
    total_balance=b;
    FILE* file;
    if(file=fopen("defaultdata.txt","a")) {
        fprintf(file,"%i %s %lf\n",accnum,fullname,total_balance);
    }
}


