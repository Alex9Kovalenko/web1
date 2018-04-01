#ifndef BINARYIP_H
#define BINARYIP_H

#include <iostream>
#include <math.h>
#include "IPAddress.h"

using std::cout;
using std::endl;

enum Bit { _0 = 0, _1 = 1 };
typedef Bit Byte[8];	// Byte is an array of 8 Bits

struct DecimalIP;

struct BinaryIP : public IPAddress {
private:
	Byte* data;
	void swap(BinaryIP&);
public:
	explicit BinaryIP(Byte* const = nullptr);
	BinaryIP(BinaryIP const&);
	virtual ~BinaryIP();
	BinaryIP& operator=(BinaryIP const&);
	virtual void output() const;
	DecimalIP const toDecimalIP() const;
	BinaryIP const toBinaryIP() const;
};

#endif	// BINARYIP_H