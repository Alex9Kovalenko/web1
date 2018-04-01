#include "supplemental.h"

IPAddress* const createDecIP(char const *const src) {
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

IPAddress* const createBinIP(char const *const src) {
	size_t fromIndex = 0;
	size_t toIndex = 0;
	Bit* tmp = nullptr;
	Byte* bin = new Byte[4];
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 8; j++) {
			bin[i][j] = _0;
		}
	}
	for (size_t i = 0; i < 4; i++) {
		while (src[fromIndex] == ' ') fromIndex++;
		for (size_t j = fromIndex; true; j++) {
			if (src[j] == '1' || src[j] == '0') {
				continue;
			}
			toIndex = j - 1;
			for (; src[j] == ' '; j++);
			if ((src[j] == '.' || (src[j] == '\0' && i == 3))
					&& (tmp = str2byte(src, fromIndex, toIndex))) {
				for (size_t jndex = 0; jndex < 8; jndex++) {
					bin[i][jndex] = tmp[jndex];
				}
				delete tmp;
				fromIndex = j + 1;
				break;
			} else {
				delete bin;
				return nullptr;
			}
		}
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

void convertIP(char const *const buffer, IPAddress* const (*create1IP)(char const *const src),
			   IPAddress const *const (IPAddress::*to2IP)() const, char const *const name2IP) {
	IPAddress* ip = nullptr;
	if (ip = (*create1IP)(buffer)) {
		IPAddress const *const another = (ip->*to2IP)();
		cout << "Converted to " << name2IP << " : ";
		another->output();
		delete ip;
		delete another;
	} else cout << "Incorrect input!\n";
}