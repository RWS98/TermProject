//Authors: David Bogacz and Robert Shoultz
//Date: 12/10/12
//Assignment: HW6-Term Project
//File: Event Implementation File

#include "Event.h"
#include "Circuit.h"

Event::Event()
{
}

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
Event * Event::execute(int globalTime, Gate *gate, int &loops)
{
	int numOfOutputs = 0;

	for (int i = 0; i < MAX_WIRES; i++)
	{
		if (wirePtr->getOutputGatePtr(i) != NULL)
		{
			numOfOutputs++;
		}
	}

	gateNum = numOfOutputs - 1;

	Event * output = new Event[numOfOutputs];
	loops = numOfOutputs;

	if (isActual)
	{
		wirePtr->setValue(value);
		wirePtr->getOutputGatePtr(gateNum)->ReCalc();
		while (gateNum >= 0)
		{
			if (wirePtr->getOutputGatePtr(gateNum)->getOutputWirePtr()->getOutputGatePtr(0) != gate)
			{
				Event newEvent(globalTime, wirePtr->getOutputGatePtr(gateNum)->getOutputWirePtr(), wirePtr->getOutputGatePtr(gateNum)->getOutputWirePtr()->getValue());
				newEvent.setIsActual(true);
				output[gateNum] = newEvent;
			}
			else
			{
				loops = 0;
			}
			gateNum--;
		}
	}
	if (!isActual)
	{
		while (gateNum >= 0)
		{
			Event newEvent((wirePtr->getOutputGatePtr(gateNum)->getDelayTime()) + globalTime, wirePtr, value);
			newEvent.setIsActual(true);
			output[gateNum] = newEvent;
			gateNum--;
		}
	}

	return output;
}

//returns the event time
int Event::getTime() 
{
	return time;
}

void Event::setIsActual(bool b)
{
	isActual = b;
}