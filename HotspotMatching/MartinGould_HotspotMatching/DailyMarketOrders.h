#pragma once

#include "ModeOptions.h"
#include "MarketOrder.h"
#include "MarketOrderChunk.h"
#include "CommaSeparatedVariableString.h"

class DailyMarketOrders
{
public:
	DailyMarketOrders(string currencyPair, string date, CommaSeparatedVariableString &dataTRD, ModeOptions theOptions);
	~DailyMarketOrders();
	deque<MarketOrder> theDailyMarketOrders;
private:
	void DailyMarketOrders::inferMarketOrders(string currencyPair, string date, CommaSeparatedVariableString &dataTRD, ModeOptions theOptions);
	bool DailyMarketOrders::testParentChild(MarketOrder parent, MarketOrderChunk child);
};
