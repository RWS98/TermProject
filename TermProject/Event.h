//Authors: David Bogacz and Robert Schultz
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
		int gateNum; 
	public:
		Event(int eventTime, Wire *wireNum, char eventValue);
		bool operator<(const Event &ev) const;
		void execute();
		int getTime();
};

#endif //EVENT.h