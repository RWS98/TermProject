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

void Wire::setOutput(Gate * gate)
{
	out[totalOutputs] = gate;
	totalOutputs++;
}

void Wire::setInput(Gate * gate)
{
	in = gate;
}

std::string Wire::getName() {
	return this->name;
}

Gate * Wire::getInputGatePtr()
{
	return out[MAX_FANOUT];
}
