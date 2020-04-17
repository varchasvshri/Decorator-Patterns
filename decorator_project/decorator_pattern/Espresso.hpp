#ifndef Espresso_hpp
#define Espresso_hpp

#include "Beverage.hpp"

class Espresso : public Beverage
{
public:
	std::string getDescription() const override;
	double cost() const override;
};

#endif