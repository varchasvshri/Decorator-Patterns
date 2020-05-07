#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "HomeThreater.hpp"

class Screen
{
	std::string description;
public:

	Screen(std::string description){
		this->description = description;
	}

	virtual void up(){
		std::cout<<description<<" is up\n";
	}

	virtual void down(){
		std::cout<<description<<" is down\n";
	}
};

#endif