#include <iostream>
#include <algorithm>
#include "Error.h"
#include "IPAddress.h"

using namespace std;

int main()
{
	BinaryIP bip;
	BinaryIP kek(IPv6);
	bip.output();
	try {
		kek = bip;
	} catch (Error e) {
		e.getMessage();
	}
	kek.output();
	cout << endl;
	DecimalIP dip;
	dip.output();
	return 0;
}