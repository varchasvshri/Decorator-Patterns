#ifndef Cd_PLAYER_HPP
#define Cd_PLAYER_HPP

#include "HomeThreater.hpp"

class Amplifier;

class CdPlayer
{
	std::string description;
	Amplifier *amplifier;
	std::string movie;
public:
	CdPlayer(std::string description, Amplifier *amplifier){
		this->description = description;
		this->amplifier = amplifier;
	}
	virtual void on(){
		std::cout<<description<<" on\n";
	}

	virtual void off(){
		std::cout<<description<<" off\n";
	}

	virtual void play(std::string movie){
		std::cout<<"Now playing "<<movie<<std::endl;
		this->movie = movie;
	}

	virtual void eject(){
		std::cout<<description<<" ejected\n";
	}

	virtual void stop(){
		std::cout<<description<<" stopped "<<movie<<std::endl;
	}

	virtual std::string toString(){
		return description;
	}
};

#endif