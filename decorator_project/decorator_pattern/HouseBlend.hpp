#ifndef HouseBlend_hpp
#define HouseBlend_hpp

#include "Beverage.hpp"

class HouseBlend : public Beverage
{
public:
	std::string getDescription() override;
	double cost() override;
};

#endif