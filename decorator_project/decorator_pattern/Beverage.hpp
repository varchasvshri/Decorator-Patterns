#ifndef Beverage_hpp
#define Beverage_hpp

#include <string>

class Beverage{
	std::string description = "Unknown Beverage";
public:
	virtual std::string getDescription(){
		return description;
	}
	virtual float cost() = 0;
};

#endif