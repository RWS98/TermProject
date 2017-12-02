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

void Wire::setName(std::string name) {
	this->name = name;
}
std::string Wire::getName() {
	return this->name;
}