#ifndef garageopen_hpp
#define garageopen_hpp

#include "remote.hpp"

class garageopen : public command
{
	Garage *gar;
public:
	garageopen(Garage *gar){
		this->gar = gar;
	}
	virtual void execute(){
		gar->on();
	}
};

#endif