//Authors: David Bogacz and Robert Schultz
//Date: 12/10/12
//Assignment: HW6-Term Project
//Purpose: To create a basic circuit simulator to take in two input files and create a circuit and run a simulation of the created circuit
//File: Main File

#include "Circuit.h"
#include "Gate.h"
#include "Event.h"
#include <vector>
#include <queue>
#include <iostream>

using namespace std; 

int main() {

	cout << "Circuit Simulator: " << endl << "\t";

	Circuit theCircuit;
	string fileName;

	cout << "What circuit file would you like to open?  ";
	cin >> fileName;
	theCircuit.parseCircuit(fileName);
	cout << "\tWhat vector file would you like to open?  ";
	cin >> fileName;
	theCircuit.parseVector(fileName);

	theCircuit.simulate();

	return 0;
}