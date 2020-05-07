#ifndef PROJECTOR_HPP
#define PROJECTOR_HPP

#include "HomeThreater.hpp"

class Projector
{
	std::string description;
	DvdPlayer *dvd;
public:
	Projector(std::string description, DvdPlayer *dvd){
		this->description = description;
		this->dvd = dvd;
	}
	virtual void on(){
		std::cout<<description<<" on\n";
	}
	virtual void off(){
		std::cout<<description<<" off\n";
	}
	virtual void wideScreenMode(){
		std::cout<<description<<" in widescreen mode (16x9 aspect model)\n";
	}
};

#endif