#include "Event.h"
#include "Circuit.h"

Event::Event(int eventTime, Wire *wireNum, char eventValue) {
	time = eventTime; 
	wirePtr = wireNum;
	value = eventValue;
}

bool Event::operator<(const Event &ev) const {
	if (time > ev.time) {
		return true; 
	}
	else if (time < ev.time) {
		return false; 
	}
	else {
		if (tieBreaker > ev.tieBreaker) {
			return true;
		}
		else {
			return false; 
		}
	}
}

void Event::execute() {
	wirePtr->setValue(value);

	std::cout << wirePtr->getInputGatePtr()->getGateOutput() << std::endl;

}

int Event::getTime() {
	return time;
}
