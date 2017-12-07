#include "Gate.h"
#include "Wire.h"


//default constructor for gate
Gate::Gate() {
	in1 = NULL;
	in2 = NULL;
	out = NULL;
}

//constructor for INPUT and OUTPUT "gates"
Gate::Gate(GateType gate, Wire *w1) {
	gT = gate;
	if (gate == INPUT) {
		in1 = w1;
	}
	if (gate == OUTPUT) {
		out = w1;
	}
}

//constructor for NOT gate
Gate::Gate(GateType gate, int delay, Wire *w1, Wire *w2) {
	gT = gate;
	DelayTime = delay;
	out = w1;
	in1 = w2;
	in2 = NULL;
}

//constructor for every other two input one output gate ie. AND, NAND, NOR, OR, XOR
Gate::Gate(GateType gate, int delay, Wire *w1, Wire *w2, Wire *w3) {
	gT = gate;
	DelayTime = delay;
	out = w1;
	in1 = w2;
	in2 = w3;
}

//return the delay time of a specific gate
int Gate::getDelayTime() {
	return DelayTime;
}

//recalculate the value of a gate when one wire changes values
char Gate::ReCalc() {
	char output = getGateOutput();
	return output; 
}

GateType Gate::getGT()
{
	return gT;
}


//logic for all the gate outputs
char Gate::getGateOutput() {
	switch (gT) {
		case AND:
			if (in1->getValue() == '1' && in2->getValue() == '1') {
				return '1';
			}
			else if (in1->getValue() == '0' || in2->getValue() == '0') {
				return '0';
			}
			else if (in1->getValue() == 'X' || in2->getValue() == 'X') {
				return 'X';
			}
			
			break;
		case OR:
			if (in1->getValue() == '0' && in2->getValue() == '0') {
				return '0';
			}
			else if (in1->getValue() == '1' || in2->getValue() == '1') {
				return '1';
			}
			else if (in1->getValue() == 'X' || in2->getValue() == 'X') {
				return 'X';
			}
			break;
		case NAND:
			if (in1->getValue() == '1' && in2->getValue() == '1') {
				return '0';
			}
			else if (in1->getValue() == '0' || in2->getValue() == '0') {
				return '1';
			}
			else if (in1->getValue() == 'X' || in2->getValue() == 'X') {
				return 'X';
			}
			break;
		case NOR:
			if (in1->getValue() == '0' && in2->getValue() == '0') {
				return '1';
			}
			else if (in1->getValue() == '1' || in2->getValue() == '1') {
				return '0';
			}
			else if (in1->getValue() == 'X' || in2->getValue() == 'X') {
				return 'X';
			}
			break;
		case NOT:
			if (in1->getValue() == '1') {
				return '0';
			}
			else if (in1->getValue() == '0') {
				return '1';
			}
			else if (in1->getValue() == 'X') {
				return 'X';
			}
			break;
		case XOR:
			if ((in1->getValue() == '0' && in2->getValue() == '0') || (in1->getValue() == '1' && in2->getValue() == '1')) {
				return '0';
			}
			else if ((in1->getValue() == '1' || in2->getValue() == '1') && in1->getValue() != in2->getValue()) {
				return '1';
			}
			else if (in1->getValue() == 'X' || in2->getValue() == 'X') {
				return 'X';
			}
			break;
		case INPUT:
			return in1->getValue();
			break;
		case OUTPUT:
			return in1->getValue();
			break;
		default:
			return -1;
			break;
	}
}