#ifndef remoteControl_hpp
#define remoteControl_hpp

#include "remote.hpp"

class remoteControl{
	command *oncommand[7];
	command *offcommand[7];
public:
	virtual void setcommand(int slot, command *forOn, command *forOff){
		oncommand[slot] = forOn;
		offcommand[slot] = forOff;
	}

	virtual void on_button_pushed(int slot){
		oncommand[slot]->execute();
	}

	virtual void off_button_pushed(int slot){
		offcommand[slot]->execute();
	}
};

#endif