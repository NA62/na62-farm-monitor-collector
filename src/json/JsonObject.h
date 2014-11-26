/*
 * JsonObject.h
 *
 *  Created on: Nov 26, 2014
 *      Author: root
 */

#ifndef JSONOBJECT_H_
#define JSONOBJECT_H_

#include <sstream>
namespace na62 {
class JsonObject {
public:
	virtual ~JsonObject() {
	}
	virtual void toJson(std::stringstream& stream) {
	}
};
}
#endif /* JSONOBJECT_H_ */
