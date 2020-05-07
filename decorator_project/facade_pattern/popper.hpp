#ifndef POPPER_HPP
#define POPPER_HPP

#include "HomeThreater.hpp"

class PopcornPopper
{
	std::string description;
public:
	PopcornPopper(std::string description){
		this->description = description;
	}
	
	virtual void on(){
		std::cout<<description<<" on\n";
	}

	virtual void off(){
		std::cout<<description<<" off\n";
	}
	
	virtual void pop(){
		std::cout<<description<<" is popped\n";
	}
};

#endif