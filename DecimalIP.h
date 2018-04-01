#ifndef DECIMALIP_H
#define DECIMALIP_H

#include <iostream>
#include "IPAddress.h"
#include "BinaryIP.h"
#include "Byte.h"

using std::cout;
using std::endl;

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
	IPAddress const *const toBinaryIP() const;
	IPAddress const *const toDecimalIP() const;
};

#endif	// DECIMALIP_H