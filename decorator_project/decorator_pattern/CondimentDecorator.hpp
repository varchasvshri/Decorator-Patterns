#ifndef CondimentDecorator_hpp
#define CondimentDecorator_hpp

#include "Beverage.hpp"

class CondimentDecorator : public Beverage
{
public:
	virtual std::string getDescription() = 0;
};

#endif