#include "DecimalIP.h"
#include "BinaryIP.h"

DecimalIP::DecimalIP(unsigned char* const data) : data(data) {}

DecimalIP::DecimalIP(DecimalIP const& o) {
	if (o.data) {
		data = new unsigned char[version];
		unsigned char const *const oData = o.data;
		for (size_t i = 0; i < version; i++) {
			data[i] = oData[i];
		}
	} else {
		data = nullptr;
	}
}

DecimalIP::~DecimalIP() {
	delete[] data;
	data = nullptr;
}

DecimalIP& DecimalIP::operator=(DecimalIP const& o) {
	if (this != &o) {
		DecimalIP(o).swap(*this);
	}
	return *this;
}

void DecimalIP::output() const {
	if (data) {
		for (size_t i = 0; i < version; i++) {
			if (i) cout << '.';
			cout << (unsigned)data[i];
		}
		cout << endl;
	} else {
		cout << "There is no data in this DecimalIP!\n";
	}
}

void DecimalIP::swap(DecimalIP& o) {
	std::swap(data, o.data);
}

BinaryIP const DecimalIP::toBinaryIP() const {
	Byte* binData = nullptr;
	if (data) {
		Byte tmp;
		binData = new Byte[version];
		unsigned char currentDec = 0u;
		for (size_t i = 0; i < version; i++) {
			currentDec = data[i];
			for (int base = 7, power = 128; base >= 0; base--, power /= 2) {
				if (power > currentDec) {
					tmp[7 - base] = _0;
				} else {
					tmp[7 - base] = _1;
					currentDec -= power;
				}
			}
			for (size_t j = 0; j < 8; j++) {
				binData[i][j] = tmp[j];
			}
		}
	}
	return BinaryIP(binData);
}

DecimalIP const DecimalIP::toDecimalIP() const { return *this; }