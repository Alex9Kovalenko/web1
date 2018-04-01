#include <iostream>
#include "IPAddress.h"
#include "supplemental.h"

using std::cin;
using std::cout;

int main() {
	bool flag = true;
	char buffer[256];
	do {
		cout << "Press any key to perform a new conversion...\n";
		cin.get();
		system("cls");
		cout << "Enter <1> if you want to convert DecimalIP to BinaryIP...\n"
			 << "Enter <2> if you want to convert BinaryIP to DecimalIP...\n"
			 << "Enter <0> to exit the program...\n";
		switch (cin.get()) {
		case '1' :
			enterIP(buffer, "DecimalIP");
			convertIP(buffer, &createDecIP, &IPAddress::toBinaryIP, "BinaryIP");
			break;
		case '2' :
			enterIP(buffer, "BinaryIP");
			convertIP(buffer, &createBinIP, &IPAddress::toDecimalIP, "DecimalIP");
			break;
		case '0' :
			flag = false;
			break;
		default :
			cout << "Try again!\n";
		}
	} while (flag);
	return 0;
}