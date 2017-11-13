#pragma once
class MarketOrderChunk
{
public:
	MarketOrderChunk(string inputline);
	~MarketOrderChunk();
	int price, month, day, hour, minute, number;
	double time, second, size;
	bool buyOrder;
};

