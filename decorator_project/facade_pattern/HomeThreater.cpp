#include "HomeThreater.hpp"

int main()
{
	Amplifier* amp = new Amplifier("Top-O-Line Amplifier");
	Tuner* tuner = new Tuner("Top-O-Line AM/FM Tuner", amp);
	DvdPlayer* dvd = new DvdPlayer("Top-O-Line DVD Player", amp);
	CdPlayer* cd = new CdPlayer("Top-O-Line CD Player", amp);
	Projector* projector = new Projector("Top-O-Line Projector", dvd);
	ThreaterLights* lights = new ThreaterLights("Theater Ceiling Lights");
	Screen* screen = new Screen("Theater Screen");
	PopcornPopper* popper = new PopcornPopper("Popcorn Popper");

	HomeThreaterFacade* homeThreater = 
			new HomeThreaterFacade(amp, tuner, dvd, cd, 
					projector, screen, lights, popper);

	homeThreater->watchMovie("Raiders of the Lost Ark");
	homeThreater->endMovie();

	return 0;
}