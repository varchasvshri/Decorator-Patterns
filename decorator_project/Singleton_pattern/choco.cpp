#include <iostream>
#include "chocolate_boiler.hpp"

ChocolateBoiler* ChocolateBoiler::uniqueInstance = NULL;

int main()
{
	ChocolateBoiler* boiler1 = ChocolateBoiler::getInstance();
	boiler1->fill();
    boiler1->boil();
    boiler1->boil();
    boiler1->drain();
    boiler1->drain();
    boiler1->isEmpty();std::cout<<'\n';
	ChocolateBoiler* boiler2 = ChocolateBoiler::getInstance();   
	return 0;
}