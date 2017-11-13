#include "stdafx.h"
#include "ModeOptions.h"


ModeOptions::ModeOptions()
{
	// Set the Options

	// Maximum time window (in seconds) for candidate pairings between reportings in the TKS and TRD files
	windowTime = 0.5;

	// Set the working directory
	directory = "C:\\Users\\Martin\\Documents\\Visual Studio 2013\\Projects\\MartinGould_HotspotMatching\\";

	hours = setHours();

	dates = setDates();

	currencyPairs = setCurrencyPairs();

}


ModeOptions::~ModeOptions()
{
}

vector<string> ModeOptions::setDates() {

	vector<string> theDates;

	theDates.push_back("20100504");

	return theDates;

}

vector<string> ModeOptions::setCurrencyPairs() {

	vector<string> theCurrencyPairs;

	theCurrencyPairs.push_back("EURGBP");

	return theCurrencyPairs;

}

vector<int> ModeOptions::setHours() {

	vector<int> theHours;

	theHours.push_back(3);

	return theHours;

}