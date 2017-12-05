#include "Circuit.h"

Circuit::Circuit() {

}

Wire* Circuit::getWirePtrFromWireNum(int num) {
	return wireArray[num - 1];
}

Wire * Circuit::getWirePtrFromWireName(std::string s)
{
	for (int i = 0; i < MAX_WIRES; i++)
	{
		if (wireArray[i]->getName() == s)
		{
			return wireArray[i];
		}
		else
			return nullptr;
	}
}

void Circuit::checkWire(int wireNum)
{
	if (wireArray[wireNum - 1] == NULL)
	{
		Wire *temp = new Wire;
		wireArray[wireNum - 1] = temp;
	}
}

void Circuit::parseCircuit(std::string filename) {

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
		}
		if (firstWord == "AND")
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

			Gate *temp = new Gate(AND, eventTime, getWirePtrFromWireNum(output), getWirePtrFromWireNum(input1), getWirePtrFromWireNum(input2));
			gateArray[numOfGates] = temp;
			numOfGates++;
		}
		if (firstWord == "OR")
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

			Gate *temp = new Gate(OR, eventTime, getWirePtrFromWireNum(output), getWirePtrFromWireNum(input1), getWirePtrFromWireNum(input2));
			gateArray[numOfGates] = temp;
			numOfGates++;
		}
		if (firstWord == "XOR")
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

			Gate *temp = new Gate(XOR, eventTime, getWirePtrFromWireNum(output), getWirePtrFromWireNum(input1), getWirePtrFromWireNum(input2));
			gateArray[numOfGates] = temp;
			numOfGates++;
		}
		if (firstWord == "NOR")
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

			Gate *temp = new Gate(NOR, eventTime, getWirePtrFromWireNum(output), getWirePtrFromWireNum(input1), getWirePtrFromWireNum(input2));
			gateArray[numOfGates] = temp;
			numOfGates++;
		}
		if (firstWord == "NAND")
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

			Gate *temp = new Gate(NAND, eventTime, getWirePtrFromWireNum(output), getWirePtrFromWireNum(input1), getWirePtrFromWireNum(input2));
			gateArray[numOfGates] = temp;
			numOfGates++;
		}
	}

	cout << "Parsing Complete." << endl;


	file.close();
}

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

	while (!file.eof())
	{
		file >> firstWord;
			if (firstWord == "INPUT")
			{
				file >> wireName >> delayTime >> value;
				
				Event temp(delayTime, getWirePtrFromWireName(wireName), value);
				pQ.push(temp);
			}
	}

	cout << "Parsing Complete." << endl;

	file.close();
}