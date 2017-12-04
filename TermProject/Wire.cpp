#include "Wire.h"
#include "Gate.h"


Wire::Wire() {

}

void Wire::setValue(char input) {
	wireValue = input;
}

char Wire::getValue() {
	return wireValue;
}

void Wire::setName(std::string str) {
	this->name = str;
}

std::string Wire::getName() {
	return this->name;
}