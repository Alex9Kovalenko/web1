#include "BinaryIP.h"
#include "DecimalIP.h"

BinaryIP::BinaryIP(Byte* const data) : data(data) {}

BinaryIP::BinaryIP(BinaryIP const& o) {
	if (o.data) {
		data = new Byte[version];
		Byte const *const oData = o.data;
		for (size_t i = 0; i < version; i++) {
			for (size_t j = 0; j < 8; j++) {
				data[i][j] = oData[i][j];
			}
		}
	} else {
		data = nullptr;
	}
}

BinaryIP::~BinaryIP() {
	delete[] data;
	data = nullptr;
}

BinaryIP& BinaryIP::operator=(BinaryIP const& o) {
	if (this != &o) {
		BinaryIP(o).swap(*this);
	}
	return *this;
}

void BinaryIP::swap(BinaryIP& o) {
	std::swap(data, o.data);
}

void BinaryIP::output() const {
	if (data) {
		for (size_t i = 0; i < version; i++) {
			if (i) cout << '.';
			for (size_t j = 0; j < 8; j++) {
				cout << data[i][j];
			}
		}
		cout << endl;
	} else {
		cout << "There is no data in this BinaryIP!\n";
	}
}

DecimalIP const BinaryIP::toDecimalIP() const {
	unsigned char* decData = nullptr;
	if (data) {
		decData = new unsigned char[version];
		unsigned char tmp = 0u;
		for (size_t i = 0; i < version; i++) {
			for (size_t j = 0; j < 8; j++) {
				tmp += pow(2, 7 - j) * data[i][j];
			}
			decData[i] = tmp;
			tmp = 0u;
		}
	}
	return DecimalIP(decData);
}

BinaryIP const BinaryIP::toBinaryIP() const { return *this; }