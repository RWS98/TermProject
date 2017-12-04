#ifndef WIRE
#define WIRE

#include <string>

const int MAX_FANOUT = 10;

class Gate;

class Wire {
	private:
		Gate *in;
		Gate *out[MAX_FANOUT];
		std::string name = ""; 
		char wireValue = 'X';
	public:
		Wire();
		void setValue(char input);
		char getValue();
		void setName(std::string str);
		std::string getName();
};


#endif //WIRE.h