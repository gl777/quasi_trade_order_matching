#include "stdafx.h"
#include "MarketOrder.h"
#include "MarketOrderChunk.h"


MarketOrder::MarketOrder()
{
	// Set the price and size of the MarketOrder to 0
	price = 0;
	size = 0;

}

MarketOrder::~MarketOrder()
{
}

void MarketOrder::initializeMarketOrder(MarketOrderChunk theChunk)
{
	price = theChunk.price;
	month = theChunk.month;
	day = theChunk.day;
	hour = theChunk.hour;
	minute = theChunk.minute;
	second = theChunk.second;
	time = theChunk.time;
	size = theChunk.size;
	buyOrder = theChunk.buyOrder;

}

void MarketOrder::assimilateMarketOrder(MarketOrderChunk theChunk)
{
	// Set the time of the parent order to be that of the child order (which may be later in time than the original parent order)
	hour = theChunk.hour;
	minute = theChunk.minute;
	second = theChunk.second;
	time = theChunk.time;

	// Increase the size of the parent order to account for the new child order
	size = size + theChunk.size;

	// Update the price of the parent order according to the child order
	if (buyOrder) {
		price = max(price,theChunk.price);
	} else {
		price = min(price, theChunk.price);
	}

}