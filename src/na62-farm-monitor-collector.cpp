//============================================================================
// Name        : simpleEclipseCPP11Project.cpp
// Author      : Jonas Kunze (kunze.jonas@gmail.com)
//============================================================================

#include <map>
#include <utility>
#include <iostream>
#include <sstream>

#include "DimAggregator.h"
#include "json/JsonBuilder.h"

using namespace std;
using namespace na62;
int main() {

	DimAggregator aggregator;
	std::stringstream stream;
	JsonMap<std::string, std::shared_ptr<JsonObject>> statistics;
	statistics["DetectorData"] = aggregator.getDetectorDatas();
	statistics.toJson(stream);

	std::cout << stream.str();

//	DimAggregator aggregator;
//	std::stringstream stream;
//	auto detectorDatas = aggregator.getDetectorDatas();
//	detectorDatas.toJson(stream);
//
//	std::cout << stream.str();
//
//	return 0;
}

