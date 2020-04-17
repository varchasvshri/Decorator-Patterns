#ifndef milk_hpp
#define milk_hpp

#include "CondimentDecorator.hpp"

class milk : public CondimentDecorator
{
	Beverage* ptr;
public:
	milk(Beverage *beverage);
	std::string getDescription() const override;
	double cost() const override;
};

#endif