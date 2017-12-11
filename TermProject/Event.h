//Authors: David Bogacz and Robert Shoultz
//Date: 12/10/12
//Assignment: HW6-Term Project
//File: Event Header File

#ifndef EVENT
#define EVENT

#include "Wire.h"

class Event
{
	private:
		int time; 
		Wire *wirePtr;
		char value;
		int tieBreaker;
		static int eventNum;
		int gateNum = 0;
		bool isActual = false;
	public:
		Event();
		Event(int eventTime, Wire *wireNum, char eventValue);
		bool operator<(const Event &ev) const;
		Event * execute(int globalTime, Gate *gate, int &loops);
		int getTime();
		void setIsActual(bool b);
};

#endif //EVENT.h