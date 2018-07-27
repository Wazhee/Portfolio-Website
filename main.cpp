#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "CAA HeaderFile.hpp"

//prototypes
int getnum();
bool searchUser(string info[], string passfile[], string username);

using namespace std;

int main()
{
    int num = 0;
    string use = "yes";
    cout << "Did you want to erase the previous program setting?(yes or no): ";
    getline(cin, use);
    if(use == "no")
    {
        num = getnum();
    }
    
    cout << num << endl;
    
    string infofile[81] = {"user1.txt", "user2.txt", "user3.txt", "user4.txt", "user5.txt",
        "user6.txt", "user7.txt", "user8.txt", "user9.txt", "user10.txt", "user11.txt", "user12.txt", "user13.txt", "user14.txt", "user15.txt", "user16.txt", "user17.txt", "user18.txt", "user19.txt", "user20.txt"};
    string passfile[81] = {"pass1.txt", "pass2.txt", "pass3.txt", "pass4.txt", "pass5.txt",
        "pass6.txt", "pass7.txt", "pass8.txt", "pass9.txt", "pass10.txt", "pass11.txt", "pass12.txt", "pass13.txt", "pass14.txt", "pass15.txt", "pass16.txt", "pass17.txt", "pass18.txt", "user19.txt", "user20.txt"};
    int run = 0;
    while(run != 4)
    {
        menu();
        cin >> run;

        while(run == 1)
        {
            run1(num);
            num++;
            menu();
            cin >> run;
            saveNum(num);
            
        }
        //If user enters 2
        while(run == 2)
        {
            cin.ignore();
            string username;
            cout << "Please enter your username: " ;
            getline(cin, username);

            //bool found = false!
            
            if(!searchUser(infofile, passfile, username))
            {
                cout << "That username was not found in our records!" << endl;
            }
            else if(searchUser(infofile, passfile, username))
            {
                cout << "Username found!" << endl;
            }
//            string info[4];
//            for(int i = 0; i < 20; i++)
//            {
//                //open file of position i in the infofile array
//                searchU.open(infofile[i], ios::in);
//                for(int b = 0; b < 4; b++)
//                {
//                    searchU >> info[b];
//                    if(info[0] == username)
//                    {
//                        cout << "They Match" <<endl;
//                        found = true;
//                    }
//                    //close file
//                    searchU.close();
//
//                }
//
//
//            }
//            searchP.open(passfile[i], ios::in);
//            cout << "Please enter the username for: " << username;
//            searchP.close();
            
            menu();
            cin >> run;
//            cout << "\nPlease enter your account number(If you have forgotten your account number please enter the number '0'): ";
//            cin >> num;
//            cout << "passFilel[num] = " << passFile[num] << endl;
//            recovery.open(passFile[num], ios::in /*| ios::binary */);
//            userFile.open(infofile[num], ios::in);
//            if (!recovery) {
//                cout << "ERROR! Could not open recovery file" << endl;
//                break;
//            }
//
//            recovery >> pass;
//
//            cout << "Pass: " << pass << endl;
//            cin.ignore();
//            cout << "Please enter the password for this account: ";
//            getline(cin, passtry);
//            if(passtry == pass)
//            {
//                //saves information from the file to info array
//                string info[3];
//                cout << "\nAccount Unlocked" << endl;
//                cout << "\n\n\n\n" << endl;
//                cout << "Here is your account info " << endl;
//                while(!userFile.eof())
//                {
//                    for(int i = 0; i < 3; i++)
//                    {
//                        userFile >> info[i];
//                    }
//                }
//                for(int i = 0; i < 3; i++)
//                {
//                    if(i == 0)
//                    {
//                        cout << "First Name: ";
//                    }
//                    else if(i == 1)
//                    {
//                        cout << "Last Name: ";
//                    }
//                    else if(i == 2)
//                    {
//                        cout << "Email: ";
//                    }
//                    cout << info[i] << endl << endl;
//
//                }
//            }
//            else if(passtry != pass)
//            {
//                cout << "\nAccount encrypted!" << endl;
//            }
//            recovery.close();
//            userFile.close();
          
//        }
//        while(run == 3)
//        {
//            cout << "Got Here" << endl;
//        }
        }
    return 0;
    }
}
int getnum()
{
    string numString;
    int num = 0;
    fstream acc;
    //open the numOf file
    acc.open("numof.txt", ios::in);
    acc >> numString;
    
    if(isdigit(numString[0]))
    {
        //converting a char to an int
        //int x = (int)numString[0] - 48;
        //converting a string to an int use stoi
        num = stoi(numString);
    }
    acc.close();
    return num;
}
bool searchUser(string infofile[], string passfile[], string username)
{
    
    fstream searchU;
    string info[4], pass, passtry;
    int num = 0;
    bool found = false;
    for(int i = 0; i < 20; i++)
    {
        //open file of position i in the infofile array
        searchU.open(infofile[i], ios::in);
        for(int b = 0; b < 4; b++)
        {
            searchU >> info[b];
            if(info[0] == username)
            {
                //found = true;
                num = i;
                cout << "Num: " << num << endl;
            }
            //close file
            searchU.close();
            
        }
        i = 20;
    }
    fstream password;
    password.open(passfile[num], ios::in);
    
    password >> pass;
    cout <<"\n\n\n";
    cout << "password: " << pass << endl;
    cout << "Please enter the password for " << username << ": ";
    getline(cin, passtry);
    if(pass == passtry)
    {
        cout << "Account Unlocked" << endl;
        found = true;
    }
    else
    {
        cout << "Sorry the password that you have entered is incorrect" << endl;
        int attempts = 3;
        for(int i = 0; i < 2; i++)
        {
            attempts--;
            cout << "You have " << attempts << " left" << endl;
            cout << "Please enter the password for " << username << ": ";
            getline(cin, passtry);
            if(pass == passtry)
            {
                cout << "Account Unlocked" << endl;
                found = true;
                i = 2;
            }
        }
        cout << "Sorry, you've exceed your total number of attempts\n";
    }
    password.close();
    return found;
}







