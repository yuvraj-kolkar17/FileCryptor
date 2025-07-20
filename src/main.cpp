#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <limits>  

#include "auth.h"
#include "encryptor.h"

using namespace std;
namespace fs = std::filesystem;

void listFilesInVault() {
    cout << "\nEncrypted Files in Vault:\n";
    
    if (!fs::exists("vault") || fs::is_empty("vault")) {
        cout << " (No files in vault)\n";
        return;
    }
    
    for (const auto &entry : fs::directory_iterator("vault")) {
        if (entry.is_regular_file()) {
            cout << " - " << entry.path().filename().string() << "\n";
        }
    }
}

void menu() {
    int choice;
    string src, dest, fileName;
    
    while (true) {
        cout << "\n=== FileCryptor Menu ===\n";
        cout << "1. Upload File to Vault\n";
        cout << "2. Download File from Vault\n";
        cout << "3. List Vault Files\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        
        
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number (1-4).\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                cout << "Enter the path of file to upload: ";
                getline(cin, src);
                cout << "Enter filename to save as: ";
                getline(cin, fileName);
                encryptAndSave(src, fileName);
                break;

            case 2:
                cout << "Enter vault filename to decrypt (without .dat): ";
                getline(cin, fileName);
                cout << "Enter output path to save: ";
                getline(cin, dest);
                decryptAndRestore(fileName, dest);
                break;
                
            case 3:
                listFilesInVault();
                break;
                
            case 4:
                cout << "Exiting FileCryptor.\n";
                return;
                
            default:
                cout << "Invalid choice! Please enter a number between 1-4.\n";
                break;
        }
    }
}

int main() {
    cout << "Welcome to Safe FileCryptor...\n";

  
    fs::create_directories("config");

   
    if (!fs::exists("config/password.cfg")) {
        cout << "No password found. Please set a new password.\n";
        setPassword();
    }

    if (!verifyPassword()) {
        cout << "Wrong password!!!!\n";
        return 1;
    }

    cout << "Access Granted!\n";
    menu();
    
    return 0;
}