#ifndef IPADDRESS_H
#define IPADDRESS_H

// enum IPVersion { IPv4 = 4, IPv6 = 6 };	// maybe, later improve the program so that it can work with IPv6

struct IPAddress {
public:
	static auto const version = 4;
	explicit IPAddress();
	IPAddress(IPAddress const&);
	virtual ~IPAddress();
	virtual void output() const = 0;
	virtual IPAddress const *const toDecimalIP() const = 0;
	virtual IPAddress const *const toBinaryIP() const = 0;
};

#endif	// IPADDRESS_H