/*
 * DimAggregator.h
 *
 *  Created on: Nov 25, 2014
 *      Author: root
 */

#ifndef DIMAGGREGATOR_H_
#define DIMAGGREGATOR_H_

#include <map>
#include <memory>
#include <string>

#include "DimInfoReader.h"
#include "DetectorData.h"

#include "json/JsonObject.h"
#include "json/JsonMap.h"

namespace na62 {

class DimAggregator {
public:
	std::shared_ptr<
			JsonMap<std::string,
					std::shared_ptr<
							JsonMap<uint, std::shared_ptr<DetectorData>>> >> getDetectorDatas();

private:
	DimInfoReader infoReader;
};

}
/* namespace na62 */

#endif /* DIMAGGREGATOR_H_ */
