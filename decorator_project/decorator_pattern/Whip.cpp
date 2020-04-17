#include "Whip.hpp"

Whip::Whip(Beverage *beverage){ptr = beverage;}

std::string Whip::getDescription() const{
	return ptr->getDescription() + ", Whip";
}

double Whip::cost() const{
	return ptr->cost() + 0.20;
}