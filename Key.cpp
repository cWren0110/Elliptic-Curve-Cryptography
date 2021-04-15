
#include<iostream>
#include<sstream>
#include<fstream>
#include<time.h>
using namespace std;
#include "Key.h"
#include "BinaryFunctions.h"

Key::Key(int degree){
	group = 0;
	int order, numPolys;
	stringstream ss;
	ss << "polynomialsDeg" << degree << ".txt";
	ifstream myFile(ss.str());

	myFile >> order >> numPolys;
	srand(time(NULL));
	int polyLine = rand() % numPolys + 1;
	string trash;
	for(int i = 0; i < polyLine ; i++){
		getline(myFile,trash);
	}
	string bit;
	for(int i = 0; i <= order; i ++){
		myFile >> bit;
		if(bit == "1"){
			group += pow(2.0,order-i);
		}
	}
	//cout << "G: " << group << endl;
	q = pow(2.0,order) -1;
	//cout << "q: " << q << endl;
	generator = rand()%q+1;
	//cout << "g: " << generator << endl;
	privateKey = rand()%(q-1)+1;
	//cout << "privateKey: " << privateKey << endl;
	h = binPow(generator,privateKey,group);
	//cout << "h: " << h << endl;
}

unsigned long Key::getGroup(){
	return group;
}

unsigned long Key::getGenerator(){
	return generator;
}
	
unsigned long Key::getH(){
	return h;
}

int Key::getQ(){
	return q;
}

int Key::getPrivate(){
	return privateKey;
}