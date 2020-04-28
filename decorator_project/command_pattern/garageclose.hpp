#ifndef garageclose_hpp
#define garageclose_hpp

#include "remote.hpp"

class garageclose : public command
{
	Garage *gar;
public:
	garageclose(Garage *gar){
		this->gar = gar;
	}
	virtual void execute(){
		gar->off();
	}
};

#endif