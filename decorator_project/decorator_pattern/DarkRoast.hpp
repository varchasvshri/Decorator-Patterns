#ifndef DarkRoast_hpp
#define DarkRoast_hpp

#include "Beverage.hpp"

class DarkRoast : public Beverage
{
public:
	std::string getDescription() override;
	double cost() override;
};

#endif