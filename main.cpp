#include <iostream>
#include <limits>
#include "BinaryIP.h"	// todo: create the separate files for BinaryIP & DecimalIP
#include "DecimalIP.h"
#include "IPAddress.h"

using std::cin;
using std::cout;
using std::endl;

DecimalIP* const createDecIP(char const *const);
BinaryIP* const createBinIP(char const *const);
int const str2int(char const *const, int const, int const);
Bit* const str2byte(char const *const, int const, int const);
void enterIP(char* const, char const *const);
void convertIP(IPAddress* const (*)(char const *const), IPAddress const (IPAddress::*)() const, char const *const);

int main() {
	IPAddress* ip = nullptr;
	bool flag = true;
	char buffer[256];
	while (flag) {
		cout << "Press any key to perform a new conversion...\n";
		cin.get();
		system("cls");
		cout << "Enter <1> if you want to convert DecimalIP to BinaryIP...\n"
			 << "Enter <2> if you want to convert BinaryIP to DecimalIP...\n"
			 << "Enter <0> to exit the program...\n";
		switch (cin.get()) {
		case '1' :
			enterIP(buffer, "DecimalIP");
//			if (ip = createDecIP(buffer)) {
//				cout << "Converted to BinaryIP: ";
//				ip->toBinaryIP().output();
//				delete ip;
//			} else cout << "Incorrect input!\n";
			convertIP(createDecIP(buffer), IPAddress::toBinaryIP(), "BinaryIP");
			break;
		case '2' :
			enterIP(buffer, "BinaryIP");
			if (ip = createBinIP(buffer)) {
				cout << "Converted to DecimalIP: ";
				ip->toDecimalIP().output();
				delete ip;
			} else cout << "Incorrect input!\n";
			break;
		case '0' :
			flag = false;
			break;
		default :
			cin.clear();	// useful
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Try again!\n";
		}
	}
	return 0;
}

DecimalIP* const createDecIP(char const *const src) {
	size_t fromIndex = 0;
	size_t toIndex = 0;
	int tmp = 0;
	unsigned char* dec = new unsigned char[4];
	for (size_t i = 0; i < 4; i++) dec[i] = 0u;
	for (size_t i = 0; i < 4; i++) {
		while (src[fromIndex] == ' ') fromIndex++;
		size_t j = fromIndex;
		do {
			if (isdigit(src[j])) {
				j++;
				continue;
			}
			toIndex = j - 1;
			for (; src[j] == ' '; j++);
			if (src[j] == '.' || (src[j] == '\0' && i == 3)) {
				tmp = str2int(src, fromIndex, toIndex);
				if (tmp > 255 || tmp < 0) {
					delete dec;
					return nullptr;
				}
				dec[i] = tmp;
				fromIndex = j + 1;
				break;
			} else {
				delete dec;
				return nullptr;
			}
			j++;
		} while (true);
	}
	return new DecimalIP(dec);
}
		
		
BinaryIP* const createBinIP(char const *const src) {
	size_t fromIndex = 0;
	size_t toIndex = 0;
	Bit* tmp;
	Byte* bin = new Byte[4];
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 8; j++) {
			bin[i][j] = _0;
		}
	}
	for (size_t i = 0; i < 4; i++) {
		while (src[fromIndex] == ' ') fromIndex++;
		size_t j = fromIndex;
		do {
			if (src[j] == '1' || src[j] == '0') {
				j++;
				continue;
			}
			toIndex = j - 1;
			for (; src[j] == ' '; j++);
			if (src[j] == '.' || (src[j] == '\0' && i == 3)) {
				if (tmp = str2byte(src, fromIndex, toIndex)) {
					for (size_t jndex = 0; jndex < 8; jndex++) {
						bin[i][jndex] = tmp[jndex];
					}
					delete tmp;
				} else {
					delete bin;
					return nullptr;
				}
				fromIndex = j + 1;
				break;
			} else {
				delete bin;
				return nullptr;
			}
			j++;
		} while (true);
	}
	return new BinaryIP(bin);
}

int const str2int(char const *const src, int const from, int const to) {
	if (to < from) return -1;
	int result = 0;
	int base = 1;
	for (int i = to; i >= from; i--) {
		result += base * (src[i] - '0');
		base *= 10;
	}
	return result;
}

Bit* const str2byte(char const *const src, int const from, int const to) {
	if (to < from || to - from > 7) return nullptr;	// what to return?
	Bit* result = new Byte;
	for (size_t i = 0; i < 8; i++) {
		result[i] = _0;
	}
	for (int i = to, j = 7; i >= from; i--, j--) {
		result[j] = (src[i] == '0' ? _0 : _1);
	}
	return result;
}

void enterIP(char* const buffer, char const *const name) {
	size_t bufferSize = 0;
	char c;
	cout << "Enter the " << name << " you want to convert: ";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (; (c = cin.get()) != '\n' && bufferSize < 255; bufferSize++) {
		buffer[bufferSize] = c;
	}
	buffer[bufferSize] = '\0';
}

void convertIP(IPAddress* const (*create1IP)(char const *const src), IPAddress const (IPAddress::*to2IP)() const, char const *const name2IP) {
	IPAddress* ip = nullptr;
	if (ip = (*create1IP)(buffer)) {
		cout << "Converted to " << name2IP << " : ";
		ip->(*to2IP)().output();
		delete ip;
	} else cout << "Incorrect input!\n";
}