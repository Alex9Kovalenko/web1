#include "Error.h"

Error::Error(int number, const char* message) {
	this->number = number;
	this->message = new char[strlen(message) + 1];
	strcpy(this->message, message);
}

Error::Error(const Error& e) {
	number = e.number;
	message = new char[strlen(e.message) + 1];
	strcpy(message, e.message);
}

Error::~Error(void) {
	delete[] message;
}

void Error::getMessage(void) {
	cout << "Error #" << number << "! " << message << endl;
}