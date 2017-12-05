#include "Circuit.h"
#include "Gate.h"
#include "Event.h"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


int main() {
	/*
	Wire *w1 = new Wire();
	Wire *w2 = new Wire();
	Wire *w3 = new Wire();

	Event *ev1 = new Event(1, w1, 'X');
	Event *ev2 = new Event(5, w2, '0');
	Event *ev3 = new Event(2, w3, '1');

	queueTest.push(*ev1);
	queueTest.push(*ev2);
	queueTest.push(*ev3);
	
	while (!queueTest.empty()) {
		Event currEvent = queueTest.top();
		queueTest.pop();
		cout << currEvent.getTime() << "\t";
	}
	*/
	/*Gate gate;

	Wire *wire0 = new Wire();
	Wire *wire1 = new Wire();
	Wire *wireX = new Wire();

	wire0->setValue('0');
	wire1->setValue('1');
	wireX->setValue('X');


	char c = gate.getGateOutput(XOR, wire0, wire0);
	cout << c << endl;
	c = gate.getGateOutput(XOR, wire0, wire1);
	cout << c << endl;
	c = gate.getGateOutput(XOR, wire1, wire0);
	cout << c << endl;
	c = gate.getGateOutput(XOR, wire1, wire1);
	cout << c << endl;
	c = gate.getGateOutput(XOR, wire0, wireX);
	cout << c << endl;
	c = gate.getGateOutput(XOR, wireX, wire0);
	cout << c << endl;
	c = gate.getGateOutput(XOR, wire1, wireX);
	cout << c << endl;
	c = gate.getGateOutput(XOR, wireX, wire1);
	cout << c << endl;
	c = gate.getGateOutput(XOR, wireX, wireX);
	cout << c << endl;*/

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