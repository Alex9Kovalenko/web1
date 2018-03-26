#include "IPAddress.h"

// IPAddress
IPAddress::IPAddress(IPVersion const version) : version(version) {}

IPAddress::IPAddress(IPAddress const& o) : version(o.version) {}

IPAddress::~IPAddress() {}

IPVersion const IPAddress::getVersion() const { return version; }


//BinaryIP
BinaryIP::BinaryIP(IPVersion const version) : IPAddress(version), data(new Byte[version]) {
	cout << "ctor\n";
	for (size_t i = 0; i < version; i++) {
		for (size_t j = 0; j < 8; j++) {
			data[i][j] = (i + j) % 2 ? _0 : _1;
		}
	}
}

BinaryIP::BinaryIP(BinaryIP const& o) : IPAddress(o.getVersion()), data(new Byte[getVersion()]) {
	Byte const *const oData = o.getData();
	for (size_t i = 0, version = getVersion(); i < version; i++) {
		for (size_t j = 0; j < 8; j++) {
			data[i][j] = oData[i][j];
		}
	}
}

Byte const *const BinaryIP::getData() const { return data; }

BinaryIP::~BinaryIP() {
	delete[] data;
	cout << "dtor\n";
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
	for (size_t i = 0, version = getVersion(); i < version; i++) {
		if (i) cout << '.';
		for (size_t j = 0; j < 8; j++) {
			cout << data[i][j];
		}
	}
	cout << endl;
}

// DecimalIP
DecimalIP::DecimalIP(IPVersion const version) : IPAddress(version), data(new unsigned char[version]) {
	cout << "ctor\n";
	for (size_t i = 0; i < version; i++) {
		data[i] = 127u;
	}
}

DecimalIP::DecimalIP(DecimalIP const& o) : IPAddress(o.getVersion()), data(new unsigned char[getVersion()]) {
	unsigned char const *const oData = o.getData();
	for (size_t i = 0, version = getVersion(); i < version; i++) {
		data[i] = oData[i];
	}
}

DecimalIP::~DecimalIP() {
	delete[] data;
	cout << "dtor\n";
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

unsigned char* const DecimalIP::getData() const { return data; }

void DecimalIP::output() const {
	for (size_t i = 0, version = getVersion(); i < version; i++) {
		if (i) cout << '.';
		cout << (unsigned)data[i];
	}
	cout << endl;
}

void DecimalIP::swap(DecimalIP& o) {
	std::swap(data, o.data);
}