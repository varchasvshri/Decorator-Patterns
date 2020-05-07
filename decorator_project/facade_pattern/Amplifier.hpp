#ifndef AMPLIFIER_HPP
#define AMPLIFIER_HPP

#include "HomeThreater.hpp"

class Amplifier
{
	std::string description;
	Tuner *tuner;
	DvdPlayer *dvd;
	CdPlayer *cd;
public:
	Amplifier(std::string description){
		this->description = description;
	}
		
	virtual void on(){
		std::cout<<description<<" on\n";
	}

	virtual void off(){
		std::cout<<description<<" off\n";
	}

	virtual void setCd(CdPlayer *cd){
		std::cout<<description<<" setting cd player to "<<cd->toString()<<std::endl;
		this->cd = cd;
	}

	virtual void setDvd(DvdPlayer *dvd){
		std::cout<<description<<" setting Dvd player to "<<dvd->toString()<<std::endl;
		this->dvd = dvd;
	}

	virtual void setTuner(Tuner *tuner){
		std::cout<<description<<" setting tuner to "<<tuner->toString()<<std::endl;
	}

	virtual void setVolume(int level){
		std::cout<<description<<" volume set to "<<level<<std::endl;
	}

	virtual void setSurroundingSound(){
		std::cout<<description<<" surrounding sound on --- speakers, subwoofers"<<std::endl;
	}
};

#endif