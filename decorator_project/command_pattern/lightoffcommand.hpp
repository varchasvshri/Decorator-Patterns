#ifndef lightoffcommand_hpp
#define lightoffcommand_hpp

#include "remote.hpp"

class lightoffcommand : public command
{
	Light *light;
public:
	lightoffcommand(Light *light){
		this->light = light;
	};
	virtual void execute(){
		light->off();
	}
	
};

#endif