
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include "BinaryFunctions.h"

string char2bin(char a,unsigned int leng){
	int asciiVal = a;
	return int2bin(asciiVal,leng);
}

string int2bin(unsigned int n,unsigned int leng){
	string result;
	do result.push_back( '0' + (n & 1) );
    while (n >>= 1);
	while(result.length()<leng){
		result.push_back('0');
	}
	reverse( result.begin(), result.end() );
    return result;
}

char bin2char(string bin){
	int result = 0;
	char letter;
	int lebin = bin.length();
	for(int i = 0; i < bin.length() ; i++){
		if(bin[i] == '1'){
			result += pow(2.0,(lebin-1)-i%lebin);
		}
	}
	letter = result;
	return letter;
}

unsigned long bin2int(string bin){
	long result = 0;
	int lebin = bin.length();
	for(int i = 0; i < bin.length() ; i++){
		if(bin[i] == '1'){
			result += pow(2.0,(lebin-1)-i%lebin);
		}
	}
	return result;
}

unsigned long binAdd(unsigned long A, unsigned long B){
	return A^B;
}

unsigned long binMult(unsigned long A, unsigned long B, unsigned long irr){
	//cout << endl << 1 << endl;
	int i = 0;
	vector<int> v;
	do{
		if(B & 1){
			v.push_back(A<<i);
		}
		i++;
	}while(B >>=1);
	//cout << endl << 2 << endl;
	int result,vecSize = v.size();
	if(v.size()>1){
		for(int j = 0; j < vecSize-1; j++){
			result = binAdd(v[v.size()-1],v[v.size()-2]);
			v.pop_back();
			v.pop_back();
			v.push_back(result);
		}
	}
	//cout << endl << 3 << endl;
	result = v[0];
	//cout << endl << 4 << endl;
	return binMod(result,irr);
}

unsigned long binMod(unsigned long A, unsigned long B){

	/*cout << "A: " << A<<endl;
	cout << "B: " << B<<endl;*/
	//cout << endl << 5 << endl;
	char as;
	unsigned long i = 1,
		          j = 1;
	int degA = int2bin(A,0).length()-1,
		degB = int2bin(B,0).length()-1;
	//cout << "degA: " << degA << endl;
	//cout << "degB: " << degB << endl;
	//degA = degB = -1;
	//char asd;
	//while(i <= A && i > 0){
	//	i <<= 1;
	//	//cout << "i: "<<i<<endl;
	//	//cout << "A: "<<A<<endl;
	//	
	//	degA++;
	//}
	////cout << endl << 6 << endl;
	//j = 1;
	//while(j <= B && j > 0){
	//	j <<= 1;
	//	degB++;
	//}
	//cout << "degA2: " << degA << endl;
	//cout << "degB2: " << degB << endl;
	//cin >> asd;
	//cout << endl << 7 << endl;
	int temp;
	if(degA >= degB){
		while(degA >= degB){
			temp = B;
			temp <<= (degA-degB);
			A = binAdd(A,temp);
			
			degA = int2bin(A,0).length()-1;
			//degA = -1;
			//i = 1;
			//while(i <= A){
			//	i <<= 1;
			//	degA++;
			//}
		}
	}
	return A;
}

unsigned long binPow(unsigned long A, unsigned long B, unsigned long irr){
	int result,
		a = A;
	//int count = 0;
	vector<int> multVec;
	
	do{
		if(('0' + (B & 1)) == '1'){
			multVec.push_back(a);
		}
		a = binMult(a,a,irr);
		//cout << endl <<"count: "<< count++;
	}while(B >>= 1);
	//cout <<endl<< "size: " <<multVec.size();
	result = multVec[0];
	for(int i = 1; i < multVec.size(); i ++){
		//cout <<endl<< multVec[i] <<"*"<<result<<endl;
		result = binMult(multVec[i],result,irr);

		//cout << endl <<"count: "<< count++;
	}
	return result;
}