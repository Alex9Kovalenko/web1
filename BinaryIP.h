#ifndef BINARYIP_H
#define BINARYIP_H

#include <iostream>
#include <math.h>
#include "IPAddress.h"
#include "DecimalIP.h"
#include "Byte.h"

using std::cout;
using std::endl;

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
	IPAddress const *const toDecimalIP() const;
	IPAddress const *const toBinaryIP() const;
};

#endif	// BINARYIP_H