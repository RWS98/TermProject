//Authors: David Bogacz and Robert Schultz
//Date: 12/10/12
//Assignment: HW6-Term Project
//File: Circuit Implementation file  

#include "Circuit.h"

//destructor 
Circuit::~Circuit()
{
	for (int i = 0; i < MAX_WIRES; i++)
	{
		delete wireArray[i];
	}
	for (int i = 0; i < MAX_GATES; i++)
	{
		delete gateArray[i];
	}
}

//gets the wire pointer from the wire number
Wire* Circuit::getWirePtrFromWireNum(int num) 
{
	return wireArray[num - 1];
}

//gets the wire pointer from the wire name
Wire * Circuit::getWirePtrFromWireName(std::string s)
{
	for (int i = 0; i < MAX_WIRES; i++)
	{
		if (wireArray[i]->getName() == s)
		{
			return wireArray[i];
		}
	}
	return nullptr;
}

//returns a pointer to the gate which leads to the output wire of the circuit
Gate * Circuit::getOutputGate()
{
	for (int i = 0; i < MAX_GATES; i++)
	{
		if (gateArray[i]->getGT() == OUTPUT) {
			return gateArray[i];
		}
	}
}

//checks if a wire has already been created and if not it creates one
void Circuit::checkWire(int wireNum)
{
	if (wireArray[wireNum - 1] == NULL)
	{
		Wire *temp = new Wire();
		wireArray[wireNum - 1] = temp;
	}
}

//parses the circuit file 
void Circuit::parseCircuit(std::string filename)
{
	using namespace std;

	ifstream file;

	string firstWord;
	string data;
	string wireName;
	int wireNum;
	int eventTime;
	int input1;
	int input2;
	int output;


	file.open(filename);

	while (!file.eof())
	{
		file >> firstWord;

		if (firstWord == "CIRCUIT")
		{
			file >> circuitName;
		}

		if (firstWord == "INPUT")
		{
			file >> wireName;

			file >> data;
			wireNum = stoi(data);
			checkWire(wireNum);
			wireArray[wireNum - 1]->setName(wireName);

			Gate *temp = new Gate(INPUT, getWirePtrFromWireNum(wireNum));
			gateArray[numOfGates] = temp;
			numOfGates++;

			getWirePtrFromWireNum(wireNum)->setInput(temp);
		}
		if (firstWord == "OUTPUT")
		{
			file >> wireName;

			file >> data;
			wireNum = stoi(data);
			checkWire(wireNum);
			wireArray[wireNum - 1]->setName(wireName);

			Gate *temp = new Gate(OUTPUT, getWirePtrFromWireNum(wireNum));
			gateArray[numOfGates] = temp;
			numOfGates++;

			getWirePtrFromWireNum(wireNum)->setOutput(temp);
		}
		if (firstWord == "NOT")
		{
			file >> data;
			data = data[0];
			eventTime = stoi(data);

			file >> data;
			input1 = stoi(data);
			checkWire(input1);

			file >> data;
			output = stoi(data);
			checkWire(output);

			Gate *temp = new Gate(NOT, eventTime, getWirePtrFromWireNum(output), getWirePtrFromWireNum(input1));
			gateArray[numOfGates] = temp;
			numOfGates++;

			getWirePtrFromWireNum(input1)->setOutput(temp);
			getWirePtrFromWireNum(output)->setInput(temp);
		}
		if (firstWord == "AND" || firstWord == "OR" || firstWord == "NAND" || firstWord == "NOR" || firstWord == "XOR")
		{
			file >> data;
			data = data[0];
			eventTime = stoi(data);

			file >> data;
			input1 = stoi(data);
			checkWire(input1);

			file >> data;
			input2 = stoi(data);
			checkWire(input2);

			file >> data;
			output = stoi(data);
			checkWire(output);

			Gate *temp = NULL;

			if (firstWord == "AND") 
			{
				temp = new Gate(AND, eventTime, getWirePtrFromWireNum(output), getWirePtrFromWireNum(input1), getWirePtrFromWireNum(input2));
			}
			if (firstWord == "OR")
			{
				temp = new Gate(OR, eventTime, getWirePtrFromWireNum(output), getWirePtrFromWireNum(input1), getWirePtrFromWireNum(input2));
			}
			if (firstWord == "NAND")
			{
				temp = new Gate(NAND, eventTime, getWirePtrFromWireNum(output), getWirePtrFromWireNum(input1), getWirePtrFromWireNum(input2));
			}
			if (firstWord == "NOR")
			{
				temp = new Gate(NOR, eventTime, getWirePtrFromWireNum(output), getWirePtrFromWireNum(input1), getWirePtrFromWireNum(input2));
			}
			if (firstWord == "XOR")
			{
				temp = new Gate(XOR, eventTime, getWirePtrFromWireNum(output), getWirePtrFromWireNum(input1), getWirePtrFromWireNum(input2));
			}

			gateArray[numOfGates] = temp;
			numOfGates++;

			getWirePtrFromWireNum(input1)->setOutput(temp);
			getWirePtrFromWireNum(input2)->setOutput(temp);
			getWirePtrFromWireNum(output)->setInput(temp);
		}
	}

	cout << "Parsing Complete." << endl;

	file.close();
}

//parse the vector input file
void Circuit::parseVector(std::string filename)
{
	using namespace std;

	ifstream file;

	string junk;
	string firstWord;
	string wireName;
	string inputValue;

	char value;
	int delayTime;

	file.open(filename);

	while (getline(file, firstWord))
	{
		file >> firstWord;
			if (firstWord == "INPUT")
			{
				file >> wireName;
				file >> delayTime;
				file >> value;
				
				Event temp(delayTime, getWirePtrFromWireName(wireName), value);
				pQ.push(temp);
			}
	}

	cout << "Parsing Complete." << endl;

	file.close();
}

void Circuit::simulate(int globalTime)
{
	/*int tempQueueSize = pQ.size();
	globalTime = time - 1;
	//run through the queue and execute each event
	while (!pQ.empty())
	{
		/*
		if (tempQueueSize != 0)
		{
			for (int i = 0; i < numOfGates; i++)
			{
				Event newEvent = gateArray[i]->ReCalc();
				newEvent.setTime(newEvent.getTime()+time);
				pQ.push(newEvent);
			}
			tempQueueSize--;
		}
		

		Event currEvent = pQ.top();
		pQ.pop();
		time = currEvent.getTime();
		if (globalTime != time)
		{
			currEvent.execute();
			globalTime++;
		}
	}*/

	int timeOutputted = 0;

	while (!pQ.empty())
	{
		int stuff = 0;
		Event currEvent = pQ.top();
		Gate *gatePtr = getOutputGate();
		globalTime = currEvent.getTime();
		pQ.pop();
		Event * returned = currEvent.execute(globalTime, gatePtr, stuff);

		for (int i = 0; i < stuff; i++)
		{
			pQ.push(returned[i]);
		}
	
		if (timeOutputted != globalTime)
		{
			std::cout << "At Time " << globalTime << " the output value is ";
			std::cout << gatePtr->getGateOutput() << std::endl;
			timeOutputted = globalTime;
		}
	}

	
}
