#ifndef stereowithCDcommand_hpp
#define stereowithCDcommand_hpp

#include "remote.hpp"

class stereoCD : public command
{
	stereo *stereo_g;
public:
	stereoCD(stereo *stereo_g){
		this->stereo_g = stereo_g;
	}
	virtual void execute(){
		stereo_g->on();
		stereo_g->setCD();
		stereo_g->setVolume(35);
	}
};
#endif