#ifndef CIRCUIT
#define CIRCUIT

#include "Gate.h"
#include "Wire.h"
#include "Event.h"
#include <fstream>
#include <vector>
#include <queue>

const int MAX_WIRES = 10;

class Circuit {
	private:
		int time;
		int numWires;
		Wire *wireArray[MAX_WIRES];
		std::priority_queue<Event> pQ;
	public:
		Circuit();
		Wire *getWirePtrFromWireNum(int num);
		void parseCircuit();
		void parseVector();
};


#endif //CIRCUIT.H
