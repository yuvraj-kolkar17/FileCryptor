#include <iostream>
#include <fstream>
#include <string>
#include "encryptor.h"

using namespace std;

void encryptAndSave(string inputPath, string vaultFileName ){
    ifstream fin(inputPath, ios::binary);
    ofstream fout("vault/" + vaultFileName + ".dat", ios::binary);

    if(!fin || !fout){
        cout<<"Error while accessing file. \n";
        return ;
    }

    char ch;
    while (fin.get(ch)){
        ch= ch^0xAA;
        fout.put(ch);
    }

    fin.close();
    fout.close();
    cout<<"file encrypted and saved....\n";
}

void decryptAndRestore(string vaultFileName, string outputPath){
    ifstream fin("vault/"+ vaultFileName+ ".dat", ios::binary);
    ofstream fout(outputPath, ios::binary);

    if(!fin || !fout){
        cout<<"error while accessing fle. \n";
        return;
    }
 char ch;
    while (fin.get(ch)) {
        ch = ch ^ 0xAA; 
        fout.put(ch);
    }

    fin.close();
    fout.close();
    cout<<"File decrypted and restored to "<< outputPath<<"\n";
}