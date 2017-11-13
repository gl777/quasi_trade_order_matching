#pragma once
class CommaSeparatedVariableString
{
public:
	CommaSeparatedVariableString(string filename);
	~CommaSeparatedVariableString();
	deque<string> theData;
};

