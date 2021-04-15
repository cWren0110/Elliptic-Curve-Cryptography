
#include<iostream>
using namespace std;

#ifndef KEY
#define KEY

class Key
{
public:
	Key(int degree);

	unsigned long getGroup();

	unsigned long getGenerator();
	
	unsigned long getH();

	int getQ();

	int getPrivate();

private:
	unsigned long group,
		generator,
		h;
	int q,
		privateKey;
};

#endif