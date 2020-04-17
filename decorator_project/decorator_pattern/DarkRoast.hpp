#ifndef DarkRoast_hpp
#define DarkRoast_hpp

#include "Beverage.hpp"

class DarkRoast : public Beverage
{
public:
	std::string getDescription() const override;
	double cost() const override;
};

#endif