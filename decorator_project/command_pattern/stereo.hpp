#ifndef stereo_hpp
#define stereo_hpp

#include "remote.hpp"

class stereo
{
	std::string location;
public:
	stereo(std::string location){
		this->location = location;
	}
	virtual void on(){
		std::cout<<location<<" stereo is on\n";
	}
	virtual void off(){
		std::cout<<location<<" stereo is off\n";
	}
	virtual void setCD(){
		std::cout<<location<<" stereo is set for CD input\n";
	}
	virtual void setVolume(int vol){
		std::cout<<location<<" stereo volume is set at ";
		std::cout<<vol<<"\n"; 
	}
};

#endif