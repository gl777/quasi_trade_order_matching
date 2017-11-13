#include "stdafx.h"
#include "DailyMarketOrders.h"
#include "MarketOrder.h"
#include "MarketOrderChunk.h"
#include "ModeOptions.h"
#include "CommaSeparatedVariableString.h"

DailyMarketOrders::DailyMarketOrders(string currencyPair, string date, CommaSeparatedVariableString &dataTRD, ModeOptions theOptions)
{
	inferMarketOrders(currencyPair, date, dataTRD, theOptions);
}


DailyMarketOrders::~DailyMarketOrders()
{
}

bool DailyMarketOrders::testParentChild(MarketOrder parent, MarketOrderChunk child){

	// Conditions to check:
	// 1. Are both orders on the same side of the book?
	// 2. Do both orders arrive at most 1 millisecond apart in time?

	bool childOrder = ((parent.buyOrder == child.buyOrder) && (abs(parent.time - child.time) < 0.0011));

	return childOrder;

}

void DailyMarketOrders::inferMarketOrders(string currencyPair, string date, CommaSeparatedVariableString &dataTRD, ModeOptions theOptions)
{

	// Initialize a deque of MarketOrderChunks
	deque<MarketOrderChunk> theChunks;

	int firstHour = theOptions.hours.front();
	int finalHour = theOptions.hours.back();

	int monthInt = stoi(date.substr(4,2));
	int dayInt = stoi(date.substr(6,2));

	// Cycle through the TRD file, create a MarketOrderChunk for each line, and push_back chunks from correct date and time window onto a deque
	for (deque<string>::iterator it = dataTRD.theData.begin(); it != dataTRD.theData.end(); it++) {
		MarketOrderChunk theChunk((*it));
		if ((theChunk.month == monthInt) && (theChunk.day == dayInt) && (theChunk.hour >= firstHour) && (theChunk.hour <= finalHour)) {
			theChunks.push_back(theChunk);
		}
	}

	// Initialize the first market order using the first chunk
	MarketOrder theMarketOrder;
	theMarketOrder.initializeMarketOrder(theChunks.front());

	// Cycle through the remaining chunks (starting at the second)
	for (deque<MarketOrderChunk>::iterator ic = theChunks.begin()+1; ic != theChunks.end(); ic++) {
		// Test whether the current chunk is a child of the parent order currently under consideration
		bool childOrder = testParentChild(theMarketOrder, (*ic));

		// If so, then assimilate
		if (childOrder) {
			theMarketOrder.assimilateMarketOrder((*ic));
		} else { // If not, then the previous parent order is complete. Push it onto the deque of MarketOrders for the day and initialize a new parent order.
			theDailyMarketOrders.push_back(theMarketOrder);
			theMarketOrder.initializeMarketOrder((*ic));
		}

	}

	cout << "Assimilating complete. There are " << theChunks.size() << " child orders and " << theDailyMarketOrders.size() << " parent orders for " << currencyPair << " on " << date << "\n";

}
