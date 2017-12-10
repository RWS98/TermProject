//Authors: David Bogacz and Robert Schultz
//Date: 12/10/12
//Assignment: HW6-Term Project
//File: Event Implementation File

#include "Event.h"
#include "Circuit.h"

//constructor for event 
Event::Event(int eventTime, Wire *wireNum, char eventValue)
{
	time = eventTime; 
	wirePtr = wireNum;
	value = eventValue;
}

//overloader operator for the priority queue 
bool Event::operator<(const Event &ev) const 
{
	if (time > ev.time) 
	{
		return true; 
	}
	else if (time < ev.time) 
	{
		return false; 
	}
	else 
	{
		if (tieBreaker > ev.tieBreaker)
		{
			return true;
		}
		else 
		{
			return false; 
		}
	}
}

//executes the simulation 
void Event::execute() 
{
		wirePtr->setValue(value);
		std::cout << "At Time " << time << " the output value is ";
		std::cout << wirePtr->getInputGatePtr(gateNum)->getGateOutput() << std::endl;
}

//returns the event time
int Event::getTime() 
{
	return time;
}
