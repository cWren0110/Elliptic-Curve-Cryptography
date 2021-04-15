
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<time.h>
using namespace std;
#include "Cryptosystem.h"
#include "BinaryFunctions.h"
#include "Key.h"

//--- Definition of encrypt ------------------------------
ostream &encrypt(istream &in,ostream &out, Key k)
{
	string str;
	stringstream ss;
	int c = 1;
	//in >> str;
	while(in >> str){
		if(str == "-.-")
			break;
		if(c ==1)
			ss << str;
		else
			ss << " " << str;
		c++;
		//in >> str;
	}

	str = ss.str();                                                                    //checked
	//cout << str;
	// if message isn't even length, add a space to the end
	//if(str.length()%2!=0)
	//	str.push_back(' ');
	vector<int> elements;
	ss.str(string());
	for(int i = 0; i < str.length(); i++)
		ss << char2bin(str[i],8);
	str = ss.str();                                                        
	//cout << str << endl;
	//cout << str.length() << endl;
	string pushElement;
	for(int j = 0; j < str.length(); j = j +8){
		pushElement = str.substr(j,8);
		pushElement.push_back('0');
		pushElement.push_back('0');
		pushElement.push_back('0');
		pushElement.push_back('0');
		pushElement.push_back('0');
		//cout << pushElement << endl;                                              
		elements.push_back(bin2int(pushElement));
	}
	srand(time(NULL));
	int y;
	unsigned long sharedSecret,
		          c1,
				  c2;
	reverse(elements.begin(),elements.end());
	int e = elements.size();
	for(int i = 0; i < e; i ++){
		//cout << endl<<"********************************************"<< endl;
		y =  rand()%(k.getQ()-1)+1;
		//cout << "y: " << y << endl;
		sharedSecret = binPow(k.getH(),y,k.getGroup()); //
		//cout << "sharedSecret: " << sharedSecret << endl;
		c1 = binPow(k.getGenerator(),y,k.getGroup()); //c1
		//cout << "c1: " << c1 << endl;
		c2 = binMult(*(elements.rbegin()),sharedSecret,k.getGroup());
		//cout << "c2: " << c2 << endl;
		//cout << "__" << endl;
		elements.pop_back();
		// cout << "^^" << endl;
		out << c1 << " " << c2 << " ";
	}
	out <<"0 0";
	//cout << out;
	return out;
}

//--- Definition of encrypt ------------------------------
ostream &encrypt(string file, Key k)
{
	
	ifstream in;
	in.open(file);
	string str;
	stringstream ss;
	int c = 1;
	//in >> str;
	while(in >> str){
		if(str == "-.-")
			break;
		if(c ==1)
			ss << str;
		else
			ss << " " << str;
		c++;
		//in >> str;
	}
	in.close();
	str = ss.str();                                                                    //checked
	//cout << str;
	// if message isn't even length, add a space to the end
	//if(str.length()%2!=0)
	//	str.push_back(' ');
	vector<int> elements;
	ss.str(string());
	for(int i = 0; i < str.length(); i++)
		ss << char2bin(str[i],8);
	str = ss.str();                                                        
	//cout << str << endl;
	//cout << str.length() << endl;
	string pushElement;
	for(int j = 0; j < str.length(); j = j +8){
		pushElement = str.substr(j,8);
		pushElement.push_back('0');
		pushElement.push_back('0');
		pushElement.push_back('0');
		pushElement.push_back('0');
		pushElement.push_back('0');
		//cout << pushElement << endl;                                              
		elements.push_back(bin2int(pushElement));
	}
	
	ofstream out;
	out.open(file);
	srand(time(NULL));
	int y;
	unsigned long sharedSecret,
		          c1,
				  c2;
	reverse(elements.begin(),elements.end());
	int e = elements.size();
	for(int i = 0; i < e; i ++){
		//cout << endl<<"********************************************"<< endl;
		y =  rand()%(k.getQ()-1)+1;
		//cout << "y: " << y << endl;
		sharedSecret = binPow(k.getH(),y,k.getGroup()); //
		//cout << "sharedSecret: " << sharedSecret << endl;
		c1 = binPow(k.getGenerator(),y,k.getGroup()); //c1
		//cout << "c1: " << c1 << endl;
		c2 = binMult(*(elements.rbegin()),sharedSecret,k.getGroup());
		//cout << "c2: " << c2 << endl;
		//cout << "__" << endl;
		elements.pop_back();
		// cout << "^^" << endl;
		out << c1 << " " << c2 << " ";
	}
	out <<"0 0";
	out.close();
	//cout << out;
	return out;
}

//--- Definition of decrypt ------------------------------
ostream & decrypt(istream &in,ostream &out, Key k){
	unsigned long c1,
				  c2,
				  temp;
	string set, message, element;
	stringstream ss;
	char tester;
	in >> c1;
	in >> c2;
	while(c1!=0){
		temp = binMult(c2,binPow(c1,k.getQ()-k.getPrivate(),k.getGroup()),k.getGroup());
		set = int2bin(temp, 13);
		set.pop_back();
		set.pop_back();
		set.pop_back();
		set.pop_back();
		set.pop_back();
		
		for(int i = 0 ;i <2;i++){
			element = set.substr(i*8,8);
			//cout << element <<endl;
			//cout <<bin2char(element)<<endl;
			//ss << bin2char(element);
			message.push_back(bin2char(element));
		}
		in >> c1;
		in >> c2;
	}
	cout<< "\n\nDecryption: ";
	for (int i = 0; i <message.length();i=i+2){
		ss << message[i];
	}
	message = ss.str();
	//cout << ss.str()<< endl;
	//reverse( message.begin(), message.end() );
	out << message;
	return out;
}

