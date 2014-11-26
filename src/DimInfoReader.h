/*
 * DimInfoReader.h
 *
 *  Created on: Nov 26, 2014
 *      Author: root
 */

#ifndef DIMINFOREADER_H_
#define DIMINFOREADER_H_

#include <string>
#include <vector>
#include <map>
#include <memory>

#include <dim/dis.hxx>
#include <dim/dic.hxx>

namespace na62 {

class DimInfoReader {
public:
	static std::map<std::string, std::string> getStrings(
			std::string dimInfoRegexp);

	static std::map<std::string, long long> getLongLong(
			std::string dimInfoRegexp);

	static std::string infoNameTohostName(std::string infoName);

	/**
	 * Returns a map with names as key and corresponding DimInfo pointer as value
	 * for every DimInfo matching the given dimInfoRegexp
	 */
	static std::map<std::string, std::shared_ptr<DimCurrentInfo>> getDimInfos(
			std::string dimInfoRegexp);

private:
	static DimBrowser dimBrowser;
	static std::map<std::string, std::shared_ptr<DimCurrentInfo>> knownDimInfos;
};

} /* namespace na62 */

#endif /* DIMINFOREADER_H_ */
