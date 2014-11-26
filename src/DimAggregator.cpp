/*
 * DimAggregator.cpp
 *
 *  Created on: Nov 25, 2014
 *      Author: root
 */

#include "DimAggregator.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

#include <utils/Utils.h>

#include <iostream>

namespace na62 {

std::shared_ptr<
		JsonMap<std::string,
				std::shared_ptr<JsonMap<uint, std::shared_ptr<DetectorData>>> >> DimAggregator::getDetectorDatas() {
	// read the ;-separated string
	auto namesAndStrings = DimInfoReader::getStrings("na62farm*/DetectorData");
	auto map = std::make_shared<JsonMap<std::string, std::shared_ptr<JsonMap<uint, std::shared_ptr<DetectorData>>>>>();
	for (auto nameAndString : namesAndStrings) {
		if (nameAndString.second.empty()) {
			continue;
		}

		std::vector<std::string> values;
		/*
		 * Remove the last ; to get rid of the empty string at the end of the list
		 */
		if (nameAndString.second.at(nameAndString.second.length() - 1) == ';') {
			nameAndString.second = nameAndString.second.substr(0,
					nameAndString.second.length() - 1);
		}
		boost::split(values, nameAndString.second, boost::is_any_of(";"));

		if (values.empty() || values.size() % 4 != 0) {
			continue;
		}

		/*
		 * detectorDatas will store the data of each sourceID
		 */
		auto detectorDatas = std::make_shared<JsonMap<uint, std::shared_ptr<DetectorData>>>();
		for (uint i = 0; i < values.size();) {
			/*
			 * The format of the dim string is sourceID;MepsReceived;missingEvents;bytesReceived;
			 */
			uint sourceID = Utils::ToUInt(values[i++]);
			uint64_t MEPsReceived = Utils::ToUInt(values[i++]);
			uint64_t missingEvents = Utils::ToUInt(values[i++]);
			uint64_t bytesReceived = Utils::ToUInt(values[i++]);

			(*detectorDatas)[sourceID] = std::make_shared<DetectorData>(MEPsReceived, missingEvents, bytesReceived);
		}

		/*
		 * Write the data of all sourceIDs to the map with the host name as key
		 */
		(*map)[DimInfoReader::infoNameTohostName(nameAndString.first)] =
		detectorDatas;
	}
	return map;
}

}
/* namespace na62 */
