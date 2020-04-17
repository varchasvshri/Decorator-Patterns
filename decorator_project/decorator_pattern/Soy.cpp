#include "Soy.hpp"

Soy::Soy(Beverage *beverage){ptr = beverage;}

std::string Soy::getDescription()const{
	return ptr->getDescription() + ", Soy";
}

double Soy::cost()const{
	return ptr->cost() + 0.20;
}