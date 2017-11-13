In the Hotspot FX data, whenever a single market order matches to several different limit orders (either at the same price or across several different prices), each partial matching is reported as a separate line in the TRD file.

The aim of the present code is to infer which lines in the TRD file acatually belong to the same "parent" market order.

The conditions to determine whether or not two "child" orders (i.e., lines in the TRD file) belong to the same "parent" market order are in the function testParentChild, which is in the class DailyMarketOrders.