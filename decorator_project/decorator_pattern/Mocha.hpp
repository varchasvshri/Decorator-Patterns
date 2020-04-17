#ifndef Mocha_hpp
#define Mocha_hpp

#include "CondimentDecorator.hpp"

class Mocha : public CondimentDecorator
{
	Beverage* moc;
public:
	Mocha(Beverage *beverage);
	std::string getDescription() const override;
	double cost() const override;
};

#endif