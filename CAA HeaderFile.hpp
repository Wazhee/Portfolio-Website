#include <iostream>
#include <string>
#ifndef CAA HEADERFILE_HPP
#define CAA HEADERFILE_HPP

using namespace std;

void menu();
void run1(int num);
void run2();
void run3();
bool check(string var1, string var2);
void saveNum(int num);

void menu()
{
    cout << "Welcome to @_wazhee's Create an Account Program" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "*This program can be used for all kinds account setups" << endl;
    cout << "\nMenu" << endl;
    cout << "1) Setup Account\n"
    << "2) Edit Account info\n" << "3) Delete Account\n"<< "4) Exit Program\n";
    cout << "\nPlease the number corresponding to the course of action you'd like to take: ";
}
void run1(int num)
{
    string infofile[81] = {"user1.txt", "user2.txt", "user3.txt", "user4.txt", "user5.txt",
        "user6.txt", "user7.txt", "user8.txt", "user9.txt", "user10.txt", "user11.txt", "user12.txt", "user13.txt", "user14.txt", "user15.txt", "user16.txt", "user17.txt", "user18.txt", "user19.txt", "user20.txt"};
    string passFile[81] = {"pass1.txt", "pass2.txt", "pass3.txt", "pass4.txt", "pass5.txt",
        "pass6.txt", "pass7.txt", "pass8.txt", "pass9.txt", "pass10.txt", "pass11.txt", "pass12.txt", "pass13.txt", "pass14.txt", "pass15.txt", "pass16.txt", "pass17.txt", "pass18.txt", "user19.txt", "user20.txt"};
    fstream intxtfile, passtxtfile;
    intxtfile.open(infofile[num], ios::out);
    passtxtfile.open(passFile[num], ios::out);
    if(intxtfile.fail())
    {
        cout << "Can't open this file!" << endl;
    }
    if(passtxtfile.fail())
    {
        cout << "Can't open this file!" << endl;
    }
    string fname;
    string lname = "";
    string pass = "";
    string passTest = "";
    string email = "";
    cin.ignore();
    //ask for the users first name
    cout << "\nFirst Name: ";
    getline(cin, fname);
    //ask for the users last name
    cout << "\nLast Name: ";
    getline(cin, lname);
    //ask for the users email
    cout << "\nEmail: ";
    getline(cin, email);
    
    //Now lets setup a username
    
    string username, usertest; //username will be the variable that is written to the file
                                //usertest will be compare to the the first user response
    cout <<".\n.\n.\n.\n";
    cout << "Now lets create your username and password\n";
    cout << "Enter a username(Characts and numbers only): ";
    getline(cin, username);
    cout << "Re-enter username: ";
    getline(cin, usertest);
    while(!check(username, usertest))
    {
        cout << "Username do not match!" << endl;
        cout << "Enter a username(Characts and numbers only): ";
        getline(cin, username);
        cout << "Re-enter username: ";
        getline(cin, usertest);
    }
    //Now lets setup a password
    
    cout << "\nPlease create a password(must be at 8 characters): ";
    getline(cin, passTest);
    cout << "\nPlease re-enter password: ";
    getline(cin, pass);
    while(!check(pass, passTest))
    {
        cout << "\nPlease create a password(must be at least 8 characters): ";
        getline(cin, passTest);
        cout << "\nPlease re-enter password: ";
        cin >> pass;
    }
    passtxtfile << pass;
    cout <<".\n.\n.\n.\n";
    //Now lets write all this info to the file
    
    intxtfile << username;
    intxtfile << "\n";
    intxtfile << fname;
    intxtfile << "\n";
    intxtfile << lname;
    intxtfile << "\n";
    intxtfile << email;
    
    cout << "\nYour account number is: " << num << "\nPlease keep this safe for this is the easiest way to access your account again" << endl;
    //remove number of account and replace with username and pass word!!!!!!!!!
    intxtfile.close();
    passtxtfile.close();
}
//check that the previous value user enter
//is the same as the new one entered
bool check(string var1, string var2)
{
    bool same = false;
    if(var1 == var2)
    {
        same = true;
    }
    return same;
}
//This function save the total number of account created
void saveNum(int num)
{
    fstream acc;
    string read;
    acc.open("numof.txt", ios::out);
    acc << num;
    acc.close();
    cout << "Opening for reading" << ".\n.\n.\n.\n";
    acc.open("numof.txt", ios::in);
    acc >> read;
    cout << "read: " << read << endl;
    acc.close();
}


//class Account
//{
//private:
//    string firstName;
//    string lastName;
//    string password;
//    string email;
//public:
//    Account();
//    Account(string first, string last, string pass, string e);
//    void setname(string first, string last);
//    void setpass(string pass);
//    void setemail(string e);
//    string getname();
//    string getpass();
//    string getemail();
//};
//Account::Account()
//{
//    firstName = "Jason";
//    lastName = "Uwaeze";
//    password = "1234";
//    email = "jtrexss@gmail.com";
//}
//Account::Account(string first, string last, string pass, string e)
//{
//    firstName = first;
//    lastName = last;
//    password = pass;
//    email = e;
//}
//void Account::setname(string first, string last)
//{
//    firstName = first;
//    lastName = last;
//}
//void Account::setpass(string pass)
//{
//    password = pass;
//}
//void Account::setemail(string e)
//{
//    email = e;
//}
//string Account::getname()
//{
//    return firstName + " " + lastName;
//}

#endif
