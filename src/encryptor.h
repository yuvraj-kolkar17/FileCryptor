#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H
#include <string>
using namespace std;


void encryptAndSave(string  inputPath, string vaultFileName);
void decryptAndRestore(string vaultFileName, string outputPath);

#endif
