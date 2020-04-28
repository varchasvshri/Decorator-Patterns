#ifndef garage_hpp
#define garage_hpp

#include "remote.hpp"

class Garage
{
	std::string location;
public:
	Garage(std::string location)
	{
		this->location = location;
	}
	virtual void on(){
		std::cout<<location<<"garage door is open now\n";
	}
	virtual void off(){
		std::cout<<location<<"garage door is closed now\n";
	}
};

#endif