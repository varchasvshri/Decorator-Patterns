#ifndef stereoOffcommand_hpp
#define stereoOffcommand_hpp

#include "remote.hpp"

class stereoOff : public command
{
	stereo *stereo_g;
public:
	stereoOff(stereo *stereo_g){
		this->stereo_g = stereo_g;
	}
	virtual void execute(){
		stereo_g->off();
	}
};
#endif