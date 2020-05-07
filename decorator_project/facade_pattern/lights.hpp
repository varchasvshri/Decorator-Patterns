#ifndef LIGHTS_HPP
#define LIGHTS_HPP

#include "HomeThreater.hpp"

class ThreaterLights
{
	std::string description;
public:
	ThreaterLights(std::string description){
		this->description = description;
	}

	virtual void on(){
		std::cout<<description<<" is on\n";
	}

	virtual void off(){
		std::cout<<description<<" is off\n";
	}

	virtual void dim(int level){
		std::cout<<description<<" dimming to "<<level<<std::endl;
	}
};

#endif