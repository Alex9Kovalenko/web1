#ifndef DECIMALIP_H
#define DECIMALIP_H

#include <iostream>
#include "IPAddress.h"

using std::cout;
using std::endl;

struct BinaryIP;

struct DecimalIP : public IPAddress {
private:
	unsigned char* data;
	void swap(DecimalIP&);
public:
	explicit DecimalIP(unsigned char* const = nullptr);
	DecimalIP(DecimalIP const&);
	virtual ~DecimalIP();
	DecimalIP& operator=(DecimalIP const&);
	virtual void output() const;
	IPAddress* toBinaryIP();
	IPAddress* toDecimalIP();
};

#endif	// DECIMALIP_H