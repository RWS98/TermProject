//Authors: David Bogacz and Robert Shoultz
//Date: 12/10/12
//Assignment: HW6-Term Project
//File: Wire Header File

#ifndef WIRE
#define WIRE

#include <string>

const int MAX_FANOUT = 10;

class Gate;

class Wire
{
	private:
		Gate *in;
		Gate *out[MAX_FANOUT];
		int totalOutputs = 0;
		std::string name = ""; 
		char wireValue = 'X';
	public:
		void setValue(char input);
		char getValue();
		void setName(std::string str);
		void setOutput(Gate *gate);
		void setInput(Gate *gate);
		std::string getName();
		Gate *getOutputGatePtr(int gateNum);
};

#endif //WIRE.h