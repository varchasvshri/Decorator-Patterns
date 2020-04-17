#ifndef Whip_hpp
#define Whip_hpp

#include "CondimentDecorator.hpp"

class Whip : public CondimentDecorator
{
	Beverage *ptr;
public:
	Whip(Beverage *beverage);
	std::string getDescription() const override;
	double cost() const override;
};

#endif