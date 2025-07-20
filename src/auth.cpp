#include<iostream>
#include<fstream>
#include<string>
#include"auth.h"

using namespace std;
string encrypt(string input){
    for (char &c : input ) c=c+3;
    return input;
}

string decrypt(string input){
    for(char &c: input) c= c-3;
    return input ;
}

bool setPassword(){
string password;
cout<<"Set a new Vaut Password: ";
cin>>password;

ofstream fout("config/password.cfg");
fout<<encrypt(password);
fout.close();
return true;
}

bool verifyPassword(){
    ifstream fin("config/password.cfg");
    if(!fin.is_open()){
        cout<<"No password found . Please set one \n";
        return setPassword();
    }


string stored, input;
fin>>stored;
stored = decrypt(stored);
cout<<"Enter vault Password";
cin>>input;

return stored == input;
}