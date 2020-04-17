#ifndef Soy_hpp
#define Soy_hpp

#include "CondimentDecorator.hpp"

class Soy : public CondimentDecorator
{
	Beverage *ptr;
public:
	Soy(Beverage *beverage);
	std::string getDescription()const  override;
	double cost()const override;
};

#endif