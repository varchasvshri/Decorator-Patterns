#include "Mocha.hpp"

Mocha::Mocha(Beverage *beverage){this->moc = beverage;}

std::string Mocha::getDescription()const{
	return moc->getDescription() + ", Mocha";
}

double Mocha::cost()const{
	return moc->cost() + 0.20;
}