#ifndef TUNER_HPP
#define TUNER_HPP

#include "HomeThreater.hpp"

class Tuner
{
	std::string description;
	Amplifier *amplifier;
	double frequency;
public:
	Tuner(std::string description, Amplifier *amplifier){
		this->description = description;
		this->amplifier = amplifier;
	}
	virtual void on(){
		std::cout<<description<<" on\n";
	}
	virtual void off(){
		std::cout<<description<<" off\n";
	}
	virtual void setFrequency(double frequency){
		std::cout<<description<<" setting frequency to "<<frequency<<std::endl;
	}
	virtual std::string toString(){
		return description;
	}
};

#endif