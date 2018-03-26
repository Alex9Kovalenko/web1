#ifndef IPADDRESS_H
#define IPADDRESS_H

#include <iostream>
#include "Error.h"

enum IPVersion { IPv4 = 4, IPv6 = 6 };
enum Bit { _0 = 0, _1 = 1 };
typedef Bit Byte[8];	// Byte is an array of 8 Bits

using namespace std;

struct IPAddress {
private:
	IPVersion const version;
public:
	explicit IPAddress(IPVersion const = IPv4);
	IPAddress(IPAddress const&);
	virtual ~IPAddress();
	// This class does not have the operator=() override, because there is no point in changing the <version>
	virtual void output() const = 0;
	IPVersion const getVersion() const;
};

struct BinaryIP : public IPAddress {
private:
	Byte* data;
	void swap(BinaryIP&);
public:
	explicit BinaryIP(IPVersion const = IPv4);
	BinaryIP(BinaryIP const&);
	virtual ~BinaryIP();
	BinaryIP& operator=(BinaryIP const&);
	Byte const *const getData() const;
	virtual void output() const;
};

struct DecimalIP : public IPAddress {
private:
	unsigned char* data;
	void swap(DecimalIP&);
public:
	explicit DecimalIP(IPVersion const = IPv4);
	DecimalIP(DecimalIP const&);
	virtual ~DecimalIP();
	DecimalIP& operator=(DecimalIP const&);
	unsigned char* const getData() const;
	virtual void output() const;
};

#endif	// IPADDRESS_H