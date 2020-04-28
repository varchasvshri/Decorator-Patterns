#ifndef lightoncommand_hpp
#define lightoncommand_hpp

#include "remote.hpp"

class lightoncommand : public command
{
	Light *light;
public:
	lightoncommand(Light *light){
		this->light = light;
	};
	virtual void execute(){
		light->on();
	}
	
};

#endif