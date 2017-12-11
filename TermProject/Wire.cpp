//Authors: David Bogacz and Robert Shoultz
//Date: 12/10/12
//Assignment: HW6-Term Project
//File: Wire Implementation File

#include "Wire.h"
#include "Gate.h"

void Wire::setValue(char input) 
{
	wireValue = input;
}

char Wire::getValue() 
{
	return wireValue;
}

void Wire::setName(std::string str) 
{
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

std::string Wire::getName() 
{
	return this->name;
}

Gate * Wire::getOutputGatePtr(int gateNum)
{
	return out[gateNum];
}
