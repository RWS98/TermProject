#ifndef CIRCUIT
#define CIRCUIT

#include "Gate.h"
#include "Wire.h"
#include "Event.h"
#include <fstream>
#include <vector>
#include <string>
#include <queue>

#include <iostream>

const int MAX_WIRES = 10;
const int MAX_GATES = 20;

class Circuit
{
	private:
		int time;
		Wire *wireArray[MAX_WIRES];
		Gate *gateArray[MAX_GATES];
		int numOfGates = 0;
		std::string circuitName;
		std::priority_queue<Event> pQ;
	public:
		~Circuit();
		Wire *getWirePtrFromWireNum(int num);
		Wire *getWirePtrFromWireName(std::string s);
		Gate *getOutputGate();
		void checkWire(int wireNum);
		void parseCircuit(std::string filename);
		void parseVector(std::string filename);
		void simulate();
};

#endif //CIRCUIT.H
