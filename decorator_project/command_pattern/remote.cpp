#include "remote.hpp"

int main()
{
	remoteControl *remt_con = new remoteControl();

	Light *livingroomlight = new Light("Living Room");
	Light *kitchenlight = new Light("Kitchen");

	lightoncommand *on_living_room_light = new lightoncommand(livingroomlight);
	lightoncommand *on_kitchen_light = new lightoncommand(kitchenlight);
	lightoffcommand *off_living_room_light = new lightoffcommand(livingroomlight);
	lightoffcommand *off_kitchen_light = new lightoffcommand(kitchenlight);

	remt_con->setcommand(1,on_living_room_light,off_living_room_light);
	remt_con->setcommand(2,on_kitchen_light,off_kitchen_light);

	remt_con->on_button_pushed(1);
	remt_con->off_button_pushed(1);
	remt_con->off_button_pushed(1);
	remt_con->on_button_pushed(2);
	remt_con->off_button_pushed(2);
}