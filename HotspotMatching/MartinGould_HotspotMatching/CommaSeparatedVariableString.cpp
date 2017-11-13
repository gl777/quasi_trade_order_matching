#include "stdafx.h"
#include "CommaSeparatedVariableString.h"


CommaSeparatedVariableString::CommaSeparatedVariableString(string filename)
{

	string line;
	ifstream inFile(filename.c_str());

	while (getline(inFile, line)) {
		theData.push_back(line);
	}

}


CommaSeparatedVariableString::~CommaSeparatedVariableString()
{
}
