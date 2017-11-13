#pragma once
class ModeOptions
{
public:
	ModeOptions();
	~ModeOptions();
	double windowTime;
	string directory;
	vector<string> dates;
	vector<string> currencyPairs;
	vector<int> hours;
private:
	vector<string> setDates();
	vector<string> setCurrencyPairs();
	vector<int> setHours();
};

