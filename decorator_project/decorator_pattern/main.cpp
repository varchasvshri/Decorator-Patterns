#include <iostream>

#include "DarkRoast.hpp"
#include "Decaf.hpp"
#include "Espresso.hpp"
#include "HouseBlend.hpp"

#include "milk.hpp"
#include "Mocha.hpp"
#include "Soy.hpp"
#include "Whip.hpp"

int main(int argc, char const *argv[])
{
	// Espresso beverage;
	// std::cout<<beverage.getDescription()<<"--$"<<beverage.cost()<<std::endl;

	// Beverage* beverage2 = new DarkRoast();
	// beverage2 = new Mocha(beverage2);
	// beverage2 = new Mocha(beverage2);
	// beverage2 = new Whip(beverage2);
	// std::cout << beverage2->getDescription() 
	// 		  << " $" 
	// 		  << beverage2->cost() 
	// 		  << std::endl;

	Beverage* beverage3 = new Espresso();
	beverage3 = new milk(beverage3);
	beverage3 = new Mocha(beverage3);
	beverage3 = new Soy(beverage3);
	beverage3 = new Whip(beverage3);
	beverage3 = new Whip(beverage3);
	std::cout << beverage3->getDescription() 
			  << " $" 
			  << beverage3->cost() 
			  << std::endl;

	return 0;
}