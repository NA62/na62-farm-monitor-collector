/*
 * JsonBuilder.h
 *
 *  Created on: Nov 26, 2014
 *      Author: root
 */

#ifndef JSONBUILDER_H_
#define JSONBUILDER_H_

#include <iostream>
#include <map>
#include <string>

#include "JsonObject.h"

namespace na62 {

class JsonBuilder {
public:

	template<class Key>
	static void toJson(std::map<Key, std::string> map,
			std::stringstream& stream) {
		bool first = true;

		stream << "{";
		for (auto pair : map) {
			if (!first) {
				stream << ",";
			} else {
				first = false;
			}
			stream << "\"" << pair.first << "\":\"" << pair.second << "\",";
		}
		stream << "}";
	}

	template<class Key, class Value>
	static void toJson(std::map<Key, Value> map, std::stringstream& stream) {

	}

//	template<class Key1, class Key2, class Value>
//	static void toJson2(std::map<Key1, std::map<Key2, Value>> map,
//			std::stringstream& stream) {
//		stream << "{";
//
//		auto& last = *(--map.end());
//
//		for (auto pair : map) {
//			stream << "\"" << pair.first << "\":";
//			toJson<Key2, Value>(pair.second, stream);
//			stream << ",";
//
//			if (&pair != &last) {
//				stream << ",";
//			}
//		}
//		stream << "}";
//	}
};

} /* namespace na62 */

#endif /* JSONBUILDER_H_ */
