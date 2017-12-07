#ifndef GATE
#define GATE

#include "Wire.h"
#include "Circuit.h"

enum GateType { AND, OR, NAND, NOR, NOT, XOR, INPUT, OUTPUT };

class Wire;

class Gate {
	private:
		Wire *in1, *in2;
		Wire *out;
		int DelayTime;	
		GateType gT;
	public:
		Gate();
		Gate(GateType gate, Wire *w1);
		Gate(GateType gate, int delay, Wire *w1, Wire *w2);
		Gate(GateType gate, int delay, Wire *w1, Wire *w2, Wire *w3);
		int getDelayTime();
		GateType getGT();
		char ReCalc();
		char getGateOutput(GateType gate, Wire *input1, Wire *input2);
};


#endif //GATE.h