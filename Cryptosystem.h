/*--- Cryptosystem.h ----------------------------------------------------
	This file contains the prototypes on functions used to encrypt
	and decrypt data using the ElGamal cryptosystem

	The functions are:
						encrypt -- one of these functions takes an input
								   and output object in order to do the 
								   encryption, while the other takes in 
								   a file name to encrypt from.
						decrypt -- this function take an input and output
								   object in order to decrypt a given
								   message.
 
	Ethan Wade
	12/12/2013
-------------------------------------------------------------------------*/

#include<iostream>
using namespace std;
#include "BinaryFunctions.h"
#include "Key.h"

#ifndef CRYPT
#define CRYPT

ostream & encrypt(istream &in,ostream &out, Key k);
/***********************************************************************
	encrypt uses ElGamal cryptosystem in order to encrypt a message

	PRECONDITION:  The key must be defined.
	POSTCONDITION:  Data has been read from in and encrypted
					and written to out.
************************************************************************/

ostream &encrypt(string file, Key k);
/***********************************************************************
	encrypt uses ElGamal cryptosystem in order to encrypt a message 

	PRECONDITION: The file must exist and the key must be defined.
	POSTCONDITION:  Data has been read from the file, encrypted and
					written back over the files contents
************************************************************************/

ostream & decrypt(istream &in,ostream &out, Key k);
/***********************************************************************
	decrypt uses ElGamal cryptosystem in order to decrypt a message

	PRECONDITION:  The key must be defined
	POSTCONDITION:  Data has been read from in, decrypted and written
					to out.
************************************************************************/

#endif