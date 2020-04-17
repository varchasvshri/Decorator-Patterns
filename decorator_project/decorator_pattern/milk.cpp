#include "milk.hpp"

milk::milk(Beverage *beverage){ptr = beverage;}

std::string milk::getDescription() const{
	return ptr->getDescription() + ", Steamed Milk";
}

double milk::cost() const{
	return ptr->cost() + 0.10;
}