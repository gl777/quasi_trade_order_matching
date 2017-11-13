#include "stdafx.h"
#include "MarketOrderChunk.h"

MarketOrderChunk::MarketOrderChunk(string inputline)
{
	// Read the CSV string into an array
	string thesedatas[6];
	string item;

	istringstream linestream(inputline);
	int i = 0;
	while (getline(linestream, item, ',')) {
		thesedatas[i] = item;
		i++;
	}

	// Read the month and year
	int theseDates[3];
	string timeitem;
	istringstream datelinestream((thesedatas[0]));
	int j = 0;
	while (getline(datelinestream, timeitem, '/')) {
		theseDates[j] = stoi(timeitem); // Convert the string to an integer
		j++;
	}
	month = theseDates[1];
	day = theseDates[2];

	// Set the time , size, and price
	size = stod(thesedatas[4]);
	hour = stoi(thesedatas[1].substr(0, 2));
	minute = stoi(thesedatas[1].substr(3, 2));
	second = stod(thesedatas[1].substr(6, 6));
	time = (3600.0*hour) + (60.0*minute) + (second); // Time of order, expressed in seconds since midnight
	price = int(floor(100000.0*stod(thesedatas[3])+0.5)); // Price, expressed as an integer (by multiplying by reciprocal of tick size)

	// Set the side of the LOB that the marketorder HITS.  A buy order hits the ASK side of the LOB.
	if (thesedatas[2] == "B") {  // This is Hotspot's "Buy" in TRD file
		buyOrder = 1;
	}
	else {
		buyOrder = 0;
	}

}


MarketOrderChunk::~MarketOrderChunk()
{
}
