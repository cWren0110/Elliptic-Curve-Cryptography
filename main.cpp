/*--- mainDriver.cpp ----------------------------------------------------
	This is the driver program used to interface with the ElGamal
	cryptosystem files.
 

	Ethan Wade
	12/12/2013
-------------------------------------------------------------------------*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#include "BinaryFunctions.h"
#include "Key.h"
#include "Cryptosystem.h"

void MainMenu(ostream & out)
/***********************************************************************
	MainMenu displays the top level menu for the driver to test the
	ElGamal system.
************************************************************************/
{
	out << "*****************************************************************"<< endl;
	out << "*****************************************************************"<< endl;
	out << "Please enter the number of the item you'd like:" << endl;
	out << "1. Encryption"<< endl;
	out << "2. Decryption"<< endl;
	out << "3. View file contents" << endl;
	out << "0. Exit"<< endl;
}

void EncryptMenu(ostream & out)
/***********************************************************************
	EncryptMenu displays the encryption menu for when the user selects
	encryption from the main menu.
************************************************************************/
{
	out << "*****************************************************************"<< endl;
	out << "*****************************************************************"<< endl;
	out << "Please enter the number of the item you'd like:" << endl;
	out << "1. Encrypt from command line"<< endl;
	out << "2. Encrypt from file contents"<< endl;
	out << "0. Back to main menu"<< endl;
}

void DecryptMenu(ostream & out)
/***********************************************************************
	DecryptMenu displays the decryption menu for when the user selects
	decryption from the main menu.
************************************************************************/
{
	out << "*****************************************************************"<< endl;
	out << "*****************************************************************"<< endl;
	out << "Please enter the number of the item you'd like:" << endl;
	out << "1. Decrypt from command line"<< endl;
	out << "2. Decrypt from file contents"<< endl;
	out << "0. Back to main menu"<< endl;
}

int main(){
	int input;
	string file, fileReader;

	ifstream inputStream;
		
	ofstream outputStream;

	Key k(13);

	MainMenu(cout);
	cin >> input;
	while(input!=0){
		// ************************************************************
		// *** Main Menu Switch ***************************************
		// ************************************************************
		switch(input){
		case 1:  //Main->Encrypt
			EncryptMenu(cout);
			cin >> input;
			// ******************************************************************
			// *** Encryption Menu Switch ***************************************
			// ******************************************************************
			switch(input){
			case 1: //Encrypt->Command line
				outputStream.open("decrypt.txt");
				cout << "Enter the message you'd like to encrypt followed by '-.-': ";
				encrypt(cin,outputStream,k);
				outputStream.close();
				cout << "\nEncrypted message has been saved to 'decrypt.txt'\n\n"<<endl;
				break;
			case 2: //Encrypt->File
				cout << "Enter file name to encrypt: ";
				cin >> file;
				if(file=="decrypt.txt"){
					encrypt(file,k);
					//cerr << "***Cannot read from 'decrypt.txt'. Returning to Main Menu***"<<endl;
				}else{
					outputStream.open("decrypt.txt");
					inputStream.open(file);
					encrypt(inputStream,outputStream,k);
					inputStream.close();
					outputStream.close();
				}
				cout << "\nEncrypted message has been saved to 'decrypt.txt'\n\n"<<endl;
				
				
				break;
			case 0: //Encrypt->Back
				break;
			default:
				cerr << "***Invalid Input, Returning to Main Menu***"<< endl;
			}
			break;
		case 2: //Main->Decrypt
			DecryptMenu(cout);
			cin >> input;
			// ******************************************************************
			// *** Decryption Menu Switch ***************************************
			// ******************************************************************
			switch(input){
			case 1: //Decrypt->Command line
				cout << "Enter the message you'd like to decrypt followed by '0 0': ";
				decrypt(cin,cout,k);
				cout << endl <<endl;
				break;
			case 2: //Decrypt->File
				cout << "Enter file name to decrypt: ";
				cin >> file;
				inputStream.open(file);
				decrypt(inputStream,cout,k);
				cout << endl<<endl;
				inputStream.close();
				break;
			case 0://Decrypt->Back
				break;
			default:
				cerr << "***Invalid Input, Returning to Main Menu***"<< endl;
			}
			break;
		case 3: //Main->View File
			cout << "Enter file name: ";
			cin >> file;
			inputStream.open(file);
			cout <<"\n\nFile contents: ";
			while(!inputStream.eof()){
				inputStream >> fileReader;
				cout << fileReader << " ";
			}
			cout << endl;
			inputStream.close();
			break;
		case 0: //Main->Exit
			break;
		default:
			cerr << "***Invalid Input, Please try again***"<< endl;
		}
		MainMenu(cout);
		cin >> input;
	}
	
	return 0;
}