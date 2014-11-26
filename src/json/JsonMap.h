/*
 * JsonObject.h
 *
 *  Created on: Nov 26, 2014
 *      Author: root
 */

#ifndef JSONMAP_H_H
#define JSONMAP_H_H

#include <map>
#include <sstream>

#include "JsonObject.h"
#include "JsonBuilder.h"
namespace na62 {
template<class key, class value>
class JsonMap: public JsonObject, public std::map<key, value> {
public:
	virtual ~JsonMap() {
	}
	void toJson(std::stringstream& stream) {
		bool first = true;

		stream << "{";
		for (auto pair : *this) {
			if (!first) {
				stream << ",";
			} else {
				first = false;
			}

			stream << "\"" << pair.first << "\":";
//			if(std::is_base_of<std::shared_ptr, decltype(pair.second)>::value){
			pair.second->toJson(stream);
		}
		stream << "}";
	}
};
}
#endif /* JSONMAP_H_H */

