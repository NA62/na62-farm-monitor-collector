/*
 * DetectorData.h
 *
 *  Created on: Nov 26, 2014
 *      Author: root
 */

#ifndef DETECTORDATA_H_
#define DETECTORDATA_H_

#include <sys/types.h>
#include <iostream>

#include "json/JsonObject.h"

namespace na62 {
class DetectorData: public JsonObject {
public:
	uint64_t mepsReceived, missingEvents, bytesReceived;
	DetectorData() :
			mepsReceived(0), missingEvents(0), bytesReceived(0) {
	}

	DetectorData(uint mepsReceived, uint missingEvents, uint bytesReceived) :
			mepsReceived(mepsReceived), missingEvents(missingEvents), bytesReceived(
					bytesReceived) {

	}
	virtual ~DetectorData() {
	}

	void toJson(std::stringstream& stream) {
		stream << "{";
		stream << "\"mepsReceived\":" << mepsReceived << ",";
		stream << "\"missingEvents\":" << missingEvents << ",";
		stream << "\"bytesReceived\":" << bytesReceived;
		stream << "}";
	}
};
}

#endif /* DETECTORDATA_H_ */
