#include <iostream>
#include <algorithm>
#include "Error.h"

using namespace std;

enum IPVersion { IPv4 = 4, IPv6 = 6 };
enum Bit { _0 = 0, _1 = 1 };
//typedef Bit Byte[8];	// Byte is an array of 8 Bits

struct IPAddress {
private:
	IPVersion const version;
public:
	explicit IPAddress(IPVersion const = IPv4);
	IPAddress(IPAddress const&);
	virtual ~IPAddress();
//	IPAddress& operator=(IPAddress const&);	// is there any point in this operator?
// No, because there is no point in changing the version
	virtual void output() const = 0;
	IPVersion const getVersion() const;
};

struct BinaryIP : public IPAddress {
private:
//	Bit (*data)[8];
	Bit** data;
//	Byte* data;
	void swap(BinaryIP&);
public:
	explicit BinaryIP(IPVersion const = IPv4);
	BinaryIP(BinaryIP const&);
	virtual ~BinaryIP();
	BinaryIP& operator=(BinaryIP const&);
//	Byte* const getData() const;
//	Bit (* const getData() const)[8];
	Bit** const getData() const;
	virtual void output() const;
};

int main()
{
	BinaryIP bip;
	bip.output();
	return 0;
}

// IPAddress
IPAddress::IPAddress(IPVersion const version) : version(version) {}

IPAddress::IPAddress(IPAddress const& o) : version(o.version) {}

IPAddress::~IPAddress() {}

//IPAddress& IPAddress::operator=(IPAddress const& o) { version = o.version; }

IPVersion const IPAddress::getVersion() const { return version; }


//BinaryIP
BinaryIP::BinaryIP(IPVersion const version) : IPAddress(version), data(new Bit*[version]) {	
	cout << "ctor\n";
	data[0] = new Bit[version * 8];
	for (size_t i = 1; i < version; i++) {
		data[i] = data[i - 1] + 8;
	}
	
	for (size_t i = 0; i < version; i++) {
		for (size_t j = 0; j < 8; j++) {
			data[i][j] = (i + j) % 2 ? _0 : _1;
		}
	}
}

BinaryIP::BinaryIP(BinaryIP const& o) : IPAddress(o.getVersion()), data(new Bit*[getVersion()]) {
	IPVersion version = getVersion();
	data[0] = new Bit[version * 8];
	Bit** oData = o.getData();
	for (size_t i = 0; i < version; i++) {
		for (size_t j = 0; j < 8; j++) {
			data[i][j] = oData[i][j];
		}
	}
}

//Byte* const BinaryIP::getData() const { return data; }
//Bit (* const BinaryIP::getData() const)[8] { return data; }
Bit** const BinaryIP::getData() const { return data; }

BinaryIP::~BinaryIP() {
	delete[] data[0];
	delete[] data;	// the trouble is here
	cout << "dtor\n";
}

BinaryIP& BinaryIP::operator=(BinaryIP const& o) {
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
	cout << "\b\n";
}
	