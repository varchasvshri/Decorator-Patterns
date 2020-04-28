#ifndef light_hpp
#define light_hpp

#include "remote.hpp"

class Light {
	std::string location;
public:
	Light(std::string location){
		this->location = location;
	}
	virtual void on(){
		std::cout<<location<<" light is turned on\n";
	}
	virtual void off(){
		std::cout<<location<<" light is turned off\n";
	}
};

#endif