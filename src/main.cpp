#include<iostream>
#include <filesystem>
#include<fstream>
#include"auth.h"
#include"encryptor.h"
using namespace std;
namespace fs = std::filesystem;

void listFilesInVault() {
    cout << "Encrypted Files in Vault:\n";
    for (const auto &entry : fs::directory_iterator("vault")) {
        cout << " - " << entry.path().filename().string() << "\n";
    }
}

void menu(){
    int choice;
    string src, dest, fileName;
    while (true){
        cout<<"\n FileCryptor Menu:\n";
       cout << "1. Upload File to Vault\n";
        cout << "2. Download File from Vault\n";
        cout << "3. List Vault Files\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch(choice){
            case 1:
            cout<<"Enter the Path of file to uplode: ";
            cin>>src;
            cout<<"Enter File name to save: ";
            cin>>fileName;
            encryptAndSave(src, fileName);
            break;

             case 2:
                cout << "Enter vault filename to decrypt (without .dat): ";
                cin >> fileName;
                cout << "Enter output path to save: ";
                cin >> dest;
                decryptAndRestore(fileName, dest);
                break;
            case 3:
                listFilesInVault();
                break;
            case 4:
                cout << "Exiting FileCryptor.\n";
                return;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
int main(){
    cout << "Welcome to Safe FileCryptor...\n";

    // ✅ Check if password file exists, if not ask to set password
    if (!fs::exists("config/password.cfg")) {
        cout << "No password found. Please set a new password.\n";
        setPassword();  // Ask user to set password first
    }

    if (!verifyPassword()) {
        cout << "Wrong password!!!!\n";
        return 0;
    }

    cout << "Access Granted!\n";
    menu();
}
