#include "Gate.h"
#include "Wire.h"


Gate::Gate() {
	in1 = NULL;
	in2 = NULL;
	out = NULL;
}

Gate::Gate(GateType gate, Wire *w1) {
	gT = gate;
	in1 = w1;
}

Gate::Gate(GateType gate, int delay, Wire *w1, Wire *w2) {
	gT = gate;
	DelayTime = delay;
	out = w1;
	in1 = w2;
	in2 = NULL;
}

Gate::Gate(GateType gate, int delay, Wire *w1, Wire *w2, Wire *w3) {
	gT = gate;
	DelayTime = delay;
	out = w1;
	in1 = w2;
	in2 = w3;
}

int Gate::getDelayTime() {
	return DelayTime;
}

void Gate::ReCalc() {

}

char Gate::getGateOutput(GateType gate, Wire *input1, Wire *input2) {
	switch (gate) {
		case AND:
			if (input1->getValue() == '1' && input2->getValue() == '1') {
				return '1';
			}
			else if (input1->getValue() == '0' || input2->getValue() == '0') {
				return '0';
			}
			else if (input1->getValue() == 'X' || input2->getValue() == 'X') {
				return 'X';
			}
			
			break;
		case OR:
			if (input1->getValue() == '0' && input2->getValue() == '0') {
				return '0';
			}
			else if (input1->getValue() == '1' || input2->getValue() == '1') {
				return '1';
			}
			else if (input1->getValue() == 'X' || input2->getValue() == 'X') {
				return 'X';
			}
			break;
		case NAND:
			if (input1->getValue() == '1' && input2->getValue() == '1') {
				return '0';
			}
			else if (input1->getValue() == '0' || input2->getValue() == '0') {
				return '1';
			}
			else if (input1->getValue() == 'X' || input2->getValue() == 'X') {
				return 'X';
			}
			break;
		case NOR:
			if (input1->getValue() == '0' && input2->getValue() == '0') {
				return '1';
			}
			else if (input1->getValue() == '1' || input2->getValue() == '1') {
				return '0';
			}
			else if (input1->getValue() == 'X' || input2->getValue() == 'X') {
				return 'X';
			}
			break;
		case NOT:
			if (input1->getValue() == '1') {
				return '0';
			}
			else if (input1->getValue() == '0') {
				return '1';
			}
			else if (input1->getValue() == 'X') {
				return 'X';
			}
			break;
		case XOR:
			if ((input1->getValue() == '0' && input2->getValue() == '0') || (input1->getValue() == '1' && input2->getValue() == '1')) {
				return '0';
			}
			else if ((input1->getValue() == '1' || input2->getValue() == '1') && input1->getValue() != input2->getValue()) {
				return '1';
			}
			else if (input1->getValue() == 'X' || input2->getValue() == 'X') {
				return 'X';
			}
			break;
		case INPUT:
			return input1->getValue();
			break;
		case OUTPUT:
			return input1->getValue();
			break;
		default:
			return -1;
			break;
	}
}