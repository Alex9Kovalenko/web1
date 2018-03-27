#include "IPAddress.h"

////////////////////////////////////////////////// IPAddress
IPAddress::IPAddress(IPVersion const version) : version(version) {}

IPAddress::IPAddress(IPAddress const& o) : version(o.version) {}

IPAddress::~IPAddress() {}

IPVersion const IPAddress::getVersion() const { return version; }


///////////////////////////////////////////////// BinaryIP
BinaryIP::BinaryIP(IPVersion const version, Byte* const data) : IPAddress(version), data(data) {
	cout << "ctor\n";
//	for (size_t i = 0; i < version; i++) {
//		for (size_t j = 0; j < 8; j++) {
//			data[i][j] = (i + j) % 2 ? _0 : _1;
//		}
//	}
}

// not such beautiful
BinaryIP::BinaryIP(BinaryIP const& o) : IPAddress(o.getVersion()), data(o.data ? new Byte[getVersion()] : nullptr) {
	if (o.data) {
		Byte const *const oData = o.data;
		for (size_t i = 0, version = getVersion(); i < version; i++) {
			for (size_t j = 0; j < 8; j++) {
				data[i][j] = oData[i][j];
			}
		}
	}
}

//Byte const *const BinaryIP::getData() const { return data; }

BinaryIP::~BinaryIP() {
	delete[] data;
	cout << "dtor\n";
	data = nullptr;
}

BinaryIP& BinaryIP::operator=(BinaryIP const& o) {	// suspicious implementation (throw)
	if (this != &o) {
		if (getVersion() != o.getVersion()) {
			throw Error(1, "Cannot assign to an BinaryIP with a different IPVersion!");
		}
		BinaryIP(o).swap(*this);
	}
	return *this;
}

void BinaryIP::swap(BinaryIP& o) {
	std::swap(data, o.data);
}

void BinaryIP::output() const {
	if (data) {
		for (size_t i = 0, version = getVersion(); i < version; i++) {
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
	IPVersion version = getVersion();
	unsigned char* decData = nullptr;
	// may be, I should add "data = getData()"
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
	return DecimalIP(version, decData);
}

//BinaryIP const& BinaryIP::setData(Byte* const d) {
//	delete[] data;
//	data = d;
//	return *this;
//}

/////////////////////////////////////////////////// DecimalIP
DecimalIP::DecimalIP(IPVersion const version, unsigned char* const data) : IPAddress(version), data(data) {
	cout << "ctor\n";
//	for (size_t i = 0; i < version; i++) {
//		data[i] = 127u;
//	}
}

DecimalIP::DecimalIP(DecimalIP const& o)
		: IPAddress(o.getVersion())
		, data(o.data ? new unsigned char[getVersion()] : nullptr) {
	if (o.data) {
		unsigned char const *const oData = o.data;
		for (size_t i = 0, version = getVersion(); i < version; i++) {
			data[i] = oData[i];
		}
	}
}

DecimalIP::~DecimalIP() {
	delete[] data;
	cout << "dtor\n";
	data = nullptr;
}

DecimalIP& DecimalIP::operator=(DecimalIP const& o) {	// suspicious implementation (throw)
	if (this != &o) {
		if (getVersion() != o.getVersion()) {
			throw Error(2, "Cannot assign to an DecimalIP with a different IPVersion!");
		}
		DecimalIP(o).swap(*this);
	}
	return *this;
}

//unsigned char const *const DecimalIP::getData() const { return data; }

void DecimalIP::output() const {
	if (data) {
		for (size_t i = 0, version = getVersion(); i < version; i++) {
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


//unsigned char const *const DecimalIP::getData() const {
//	return data;
//}

//DecimalIP const& DecimalIP::setData(unsigned char* const d) {
//	delete[] data;
//	data = d;
//	return *this;
//}

BinaryIP const DecimalIP::toBinaryIP() const {
	IPVersion version = getVersion();
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
	return BinaryIP(version, binData);
}