
#include<iostream>
using namespace std;

#ifndef BINFUNC
#define BINFUNC

string char2bin(char a,unsigned int leng);

string int2bin(unsigned int n,unsigned int leng);

char bin2char(string bin);

unsigned long bin2int(string bin);

unsigned long binAdd(unsigned long A,unsigned long B);

unsigned long binMult(unsigned long A, unsigned long B, unsigned long irr);

unsigned long binMod(unsigned long A, unsigned long B);

unsigned long binPow(unsigned long A, unsigned long B, unsigned long irr);

#endif