// MartinGould_HotspotMatching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ModeOptions.h"
#include "MarketOrder.h"
#include "DailyMarketOrders.h"
#include "CommaSeparatedVariableString.h"

int _tmain(int argc, _TCHAR* argv[])
{

	// Write outputs with 2 digits in the exponent (to save disk space).
	_set_output_format(_TWO_DIGIT_EXPONENT);

	// Set the options for the run (e.g., list of hours to consider)
	ModeOptions theOptions;

	for (vector<string>::iterator itcp = theOptions.currencyPairs.begin(); itcp != theOptions.currencyPairs.end(); itcp++) {
		string currencyPair = (*itcp);

		// Read the relevant TRD file into memory, as a deque of strings
		CommaSeparatedVariableString dataTRD(theOptions.directory + currencyPair + ".csv");

		for (vector<string>::iterator itd = theOptions.dates.begin(); itd != theOptions.dates.end(); itd++) {
			string date = (*itd);
			DailyMarketOrders theDailyMarketOrders(currencyPair, date, dataTRD, theOptions);
		}

	}

	return 0;
}

