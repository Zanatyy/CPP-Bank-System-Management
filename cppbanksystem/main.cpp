#include <iostream>
#include <fstream>
#include "account.h"
#include <conio.h>
#include <map>
#include <windows.h>
#include <stdio.h>
#define ESC 27
//Regarding highlight menu
#define nc 150
#define hc 200
void gotoxy(int x,int y)
{
    COORD coord={0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}
//===========================
using namespace std;
map<int , account>accounts;
map<int,account>::iterator itr;

void programbegin();
char menuitems[10][21]={"Add Account","Display Account","Display All Accounts","Deposit","Withdraw","Modify Account","Delete Account","Import Records","Delete Records","Exit"};
int main() {
    programbegin();
}
void create_account(){
    account a1;
    cout<<"Create account!\n";
    a1.setter();
    accounts.insert(pair<int,account>(a1.retacno(),a1));
}
void printaccounts(){
    for (itr = accounts.begin(); itr != accounts.end(); ++itr) {
        itr->second.show_account();
        cout<<endl;
    }
    cout<<"Press any key to continue.\n";
    getch();
}
void findandshowaccount(int i){
    account x=accounts.find(i)->second;
    x.show_account();
    cout<<"Press any key to continue.\n";
    getch();
}
void addrecords() {
    fstream FILE;
    int a; char f[10]; char l[10]; double d;
    char c[20];
    bool id=true;
    map<int,account>::iterator it;
    cout<<"Warning, Only use files written in the same format as defaultdata.txt (accnum firstname lastname balance).\n";
    cout<<"Enter file path/name.\n";
    cin>>c;
    FILE.open(c,ios::in);
    if(FILE.is_open()){
        while(FILE>>a>>f>>l>>d){
            it=accounts.find(a);
            while(it!=accounts.end()){
                if(id==true)
                    cout<<"Error duplicate IDs, automatically changing Id."<<endl;
                id=false;
                a++;
                it=accounts.find(a);
            }
            cout<<"NEW ID:"<<a<<endl;
            account newaccount(a,f,l,d);
            accounts.insert({a,newaccount});
        }
    }
    FILE.close();
    cout<<"Press any key to continue.\n";
    getch();
}
void clearrecords(){
    if(remove("defaultdata.txt")==0) cout<<"RECORDS DELETED SUCCESSFULLY\n";
    else
        printf("RECORDS DELETION FAILED.\n");
    cout<<"Press any key to continue.\n";
    getch();
}
void programbegin(){
    int Currentitem=0,quit=0,col=40,row=5,size=10,n;
    char c;
    account* currentaccount;
    printf("Mainmenu");
    textattr(nc);
    do{
        for(int i=0;i<size;i++){
            gotoxy(col,row+i);
            if(i==Currentitem) {
                textattr(hc);
                printf("%s",menuitems[i]);
            }
            else{
                textattr(nc);
                printf("%s",menuitems[i]);
            }
            textattr(nc);
        }
        c=getch();
        switch(c){
            default:
                c=getch(); //Extended Keys
                switch(c){
                    case 72: //up
                    if(Currentitem!=0) Currentitem--;
                    break;
                    case 80: //down
                    if(Currentitem<size-1) Currentitem++;
                    break;
                }
                break;
                case 13: //Enter case
                system("cls");
                printf("%s\n",menuitems[Currentitem]);
                switch(Currentitem){
                    case 0:
                        create_account();
                        system("cls");
                        break;
                    case 1:
                        cout<<"Enter account ID number.\n";
                        cin>>n;
                        findandshowaccount(n);
                        system("cls");
                        break;
                    case 2:
                        printaccounts();
                        system("cls");
                        break;
                    case 3:
                        cout<<"Enter account ID number\n";
                        cin>>n;
                        currentaccount=&accounts.find(n)->second;
                        cout<<"Enter deposit ammount.\n";
                        cin>>n;
                        currentaccount->dep(n);
                        system("cls");
                        break;
                    case 4:
                        cout<<"Enter account ID number\n";
                        cin>>n;
                        currentaccount=&accounts.find(n)->second;
                        cout<<"Enter withdrawal ammount.\n";
                        cin>>n;
                        currentaccount->draw(n);
                        system("cls");
                        break;
                    case 5:
                        cout<<"Enter account ID number\n";
                        cin>>n;
                        accounts.find(n)->second.modify();
                        system("cls");
                        break;
                    case 6:
                        cout<<"Enter account ID number\n";
                        cin>>n;
                        accounts.erase(n);
                        system("cls");
                        break;
                    case 7:
                        addrecords();
                        system("cls");
                        break;
                    case 8:
                        clearrecords();
                        system("cls");
                        break;
                    case 9:
                        quit=1;
                        system("cls");
                        break;
                }
                break;
                case 27: //Escape case
                quit=1;
                break;
        }
    } while(quit!=1);
    return;
}