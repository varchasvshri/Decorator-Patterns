#ifndef Decaf_hpp
#define Decaf_hpp

#include "Beverage.hpp"

class Decaf : public Beverage
{
public:
	std::string getDescription() override;
	double cost() override;
};

#endif