#ifndef SUPPLEMENTAL_H
#define SUPPLEMENTAL_H

#include <limits>
#include <string>
#include <iostream>
#include "IPAddress.h"
#include "DecimalIP.h"
#include "BinaryIP.h"
#include "Byte.h"

using std::size_t;
using std::cin;

IPAddress* const createDecIP(char const *const);
IPAddress* const createBinIP(char const *const);
int const str2int(char const *const, int const, int const);
Bit* const str2byte(char const *const, int const, int const);
void enterIP(char* const, char const *const);
void convertIP(char const *const, IPAddress* const (*)(char const *const),
		IPAddress const *const (IPAddress::*)() const, char const *const);

#endif	// SUPPLEMENTAL_H