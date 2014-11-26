/*
 * DimInfoReader.cpp
 *
 *  Created on: Nov 26, 2014
 *      Author: root
 */

#include "DimInfoReader.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

namespace na62 {

DimBrowser DimInfoReader::dimBrowser;
std::map<std::string, std::shared_ptr<DimCurrentInfo>> DimInfoReader::knownDimInfos;

std::map<std::string, std::string> DimInfoReader::getStrings(
		std::string dimInfoRegexp) {
	std::map<std::string, std::string> map;
	for (auto pair : getDimInfos(dimInfoRegexp)) {
		if (pair.second->getSize() > 0) {
			map[pair.first] = std::string(pair.second->getString());
		}
	}
	return map;
}

std::map<std::string, long long> DimInfoReader::getLongLong(
		std::string dimInfoRegexp) {
	std::map<std::string, long long> map;
	for (auto pair : getDimInfos(dimInfoRegexp)) {
		map[pair.first] = pair.second->getLonglong();
	}
	return map;
}

std::map<std::string, std::shared_ptr<DimCurrentInfo>> DimInfoReader::getDimInfos(
		std::string serviceRegexp) {
	char *service, *format;
	std::map<std::string, std::shared_ptr<DimCurrentInfo>> map;
	dimBrowser.getServices(serviceRegexp.c_str());

	std::shared_ptr<DimCurrentInfo> lastInfo;
	while (dimBrowser.getNextService(service, format)) {
		std::string serviceName(service);
		if (knownDimInfos.find(serviceName) != knownDimInfos.end()) {
			lastInfo = knownDimInfos[serviceName];
		} else {
			lastInfo = std::make_shared<DimCurrentInfo>(service, -1);
			knownDimInfos[serviceName] = lastInfo;
		}
		map[serviceName] = lastInfo;
	}

	return map;
}

std::string DimInfoReader::infoNameTohostName(std::string infoName) {
	return infoName.substr(0, infoName.find("/"));
}
} /* namespace na62 */
