#include "Circuit.h"
#include "Event.h"
#include "Gate.h"

Circuit::Circuit() {

}

Wire* Circuit::getWirePtrFromWireNum(int num) {
	return wireArray[num + 1];
}

void Circuit::parseCircuit() {
	std::string wireName;
	int eventTime;
	char eventValue;
	std::string strjunk;	
	
}

void Circuit::parseVector() {

}