#include <iostream>
//#include <algorithm>
#include "Error.h"
#include "IPAddress.h"	// todo: create the separate files for BinaryIP & DecimalIP

using namespace std;

int main()
{
	unsigned char* src = new unsigned char[5];
	src[0] = 17;
	src[1] = 33;
	src[2] = 65;
	src[3] = 129;
	src[4] = 134;	// problem!!!
	DecimalIP(IPv4, src).toBinaryIP().output();
	cout << endl << endl;
	
	Byte* bt = new Byte[4];
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 8; j++) {
			bt[i][j] = (i + j) % 3 ? _1 : _0;
		}
	}
	BinaryIP bip(IPv4, bt);
	bip.output();
	bip.toDecimalIP().output();
	return 0;
}