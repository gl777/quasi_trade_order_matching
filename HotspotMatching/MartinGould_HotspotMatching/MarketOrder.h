#pragma once

#include "MarketOrderChunk.h"

class MarketOrder
{
public:
	MarketOrder();
	~MarketOrder();
	int price, month, day, hour, minute;
	double second, time, size;
	bool buyOrder;
	void MarketOrder::initializeMarketOrder(MarketOrderChunk theChunk);
	void MarketOrder::assimilateMarketOrder(MarketOrderChunk theChunk);
private:
	
};
