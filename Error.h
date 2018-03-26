#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <string.h>

using namespace std;

class Error {
protected:
	int number;
	char* message;
	
public:
	Error(int number = 0, const char* message = "default message");
	Error(const Error& e);
	virtual ~Error(void);
	void getMessage(void);
};

#endif // ERROR_H