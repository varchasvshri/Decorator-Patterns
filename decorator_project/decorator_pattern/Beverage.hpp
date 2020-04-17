#ifndef Beverage_hpp
#define Beverage_hpp

#include <string>

class Beverage{
	std::string description = "Unknown Beverage";
public:
	virtual std::string getDescription() const = 0;
	virtual double cost() const = 0;
};

#endif