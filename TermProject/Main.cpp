#include "Circuit.h"
#include "Gate.h"
#include "Event.h"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


int main() {
	
	/*
	
	Gate gate;

	Wire *wire0 = new Wire();
	Wire *wire1 = new Wire();
	Wire *wireX = new Wire();

	wire0->setValue('0');
	wire1->setValue('1');
	wireX->setValue('X');

	
	char c = gate.getGateOutput(INPUT, wire0, wire0);
	cout << c << endl;
	c = gate.getGateOutput(INPUT, wire0, wire1);
	cout << c << endl;
	c = gate.getGateOutput(INPUT, wire1, wire0);
	cout << c << endl;
	c = gate.getGateOutput(INPUT, wire1, wire1);
	cout << c << endl;
	c = gate.getGateOutput(INPUT, wire0, wireX);
	cout << c << endl;
	c = gate.getGateOutput(INPUT, wireX, wire0);
	cout << c << endl;
	c = gate.getGateOutput(INPUT, wire1, wireX);
	cout << c << endl;
	c = gate.getGateOutput(INPUT, wireX, wire1);
	cout << c << endl;
	c = gate.getGateOutput(XOR, wireX, wireX);
	cout << c << endl;

	return 0; */

	Circuit theCircuit;
	string fileName;

	cout << "What circuit file would you like to open?  ";
	cin >> fileName;
	theCircuit.parseCircuit(fileName);
	cout << "What vector file would you like to open?  ";
	cin >> fileName;
	theCircuit.parseVector(fileName);

	return 0;
}