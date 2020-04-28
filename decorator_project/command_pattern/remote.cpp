#include "remote.hpp"

int main()
{
	remoteControl *remt_con = new remoteControl();

	Light *livingroomlight = new Light("Living Room");
	Light *kitchenlight = new Light("Kitchen");
	Garage *carGarage = new Garage("");
	stereo *livingroom_stereo = new stereo("Living Room");

	lightoncommand *on_living_room_light = new lightoncommand(livingroomlight);
	lightoncommand *on_kitchen_light = new lightoncommand(kitchenlight);
	lightoffcommand *off_living_room_light = new lightoffcommand(livingroomlight);
	lightoffcommand *off_kitchen_light = new lightoffcommand(kitchenlight);
	garageopen *open_garage = new garageopen(carGarage);
	garageclose *close_garage = new garageclose(carGarage);
	stereoCD *stereo_CD = new stereoCD(livingroom_stereo);
	stereoOff *stereo_close = new stereoOff(livingroom_stereo);

	remt_con->setcommand(0,on_living_room_light,off_living_room_light);
	remt_con->setcommand(1,on_kitchen_light,off_kitchen_light);
	remt_con->setcommand(2,open_garage, close_garage);
	remt_con->setcommand(3, stereo_CD, stereo_close);

	remt_con->on_button_pushed(0);
	remt_con->off_button_pushed(0);
	remt_con->off_button_pushed(0);
	remt_con->on_button_pushed(1);
	remt_con->off_button_pushed(1);
	remt_con->on_button_pushed(2);
	remt_con->off_button_pushed(2);
	std::cout<<"\n";
	remt_con->on_button_pushed(3);
	remt_con->off_button_pushed(3);
}