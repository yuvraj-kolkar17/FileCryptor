# FileCryptor

**FileCryptor** is a C++-based file encryption and decryption vault system. It provides a simple command-line interface to securely upload, download, and list encrypted files stored in a secure vault. This project ensures the confidentiality of personal files using basic encryption logic and secure password access.

## Features

- Upload files to an encrypted vault
- Download and decrypt files from the vault
- List all encrypted files stored
- Password-protected access

## Usage

To use this program, follow these steps:

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/yuvraj-kolkar17/FileCryptor.git
    ```

2. Navigate to the project directory:

    ```bash
    cd FileCryptor
    ```

3. Compile the program using g++:

    ```bash
    g++ filecryptor.cpp -o filecryptor
    ```

4. Run the program:

    ```bash
    ./filecryptor
    ```

5. Follow the on-screen menu:

    ```
     FileCryptor Menu:
     1. Upload File to Vault
     2. Download File from Vault
     3. List Vault Files
     4. Exit
    ```

### Example

## Encryption 
<img width="514" height="374" alt="image" src="https://github.com/user-attachments/assets/c0ac6b08-0b81-471b-b375-7882a7edc3cc" />

<img width="277" height="382" alt="image" src="https://github.com/user-attachments/assets/7e104127-033b-4e21-8e19-de7980b9f969" />

## Encrypted File
<img width="1565" height="776" alt="image" src="https://github.com/user-attachments/assets/e7bdccdb-562f-4edc-a1e7-7af8fb8b76d5" />

To upload a file:

- Enter the full path of the file you want to upload (e.g., `C:\Users\YourName\Desktop\example.txt`)
- Give it a name to store in the vault (e.g., `mydoc`)

To download a file:

- Enter the vault file name (e.g., `mydoc`)
- Provide the path where you want to save it (e.g., `C:\Users\YourName\Downloads`)

## Vault Password
Defualt Password = 0000

