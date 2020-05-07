#ifndef HOMETHREATRE_FACADE_HPP
#define HOMETHREATRE_FACADE_HPP

#include "HomeThreater.hpp"

class HomeThreaterFacade
{
	Amplifier *amp;
	Tuner *tune;
	DvdPlayer *dvd;
	CdPlayer *cd;
	Projector *projector;
	ThreaterLights *lights;
	Screen *screen;
	PopcornPopper *popper;

public:
	HomeThreaterFacade(Amplifier *amp,
	Tuner *tune,
	DvdPlayer *dvd,
	CdPlayer *cd,
	Projector *projector,
	Screen *screen,
	ThreaterLights *lights,
	PopcornPopper *popper){
		this->amp = amp;
		this->tune = tune;
		this->dvd = dvd;
		this->cd = cd;
		this->projector = projector;
		this->lights = lights;
		this->screen = screen;
		this->popper = popper;
	}
	
	virtual void watchMovie(std::string movie){
		std::cout<<"Get ready to watch a movie...\n";
		popper->on();
		popper->pop();
		lights->dim(10);
		screen->down();
		projector->on();
		projector->wideScreenMode();
		amp->on();
		amp->setDvd(dvd);
		amp->setSurroundingSound();
		amp->setVolume(5);
		dvd->on();
		dvd->play(movie);
	}

	virtual void endMovie(){
		std::cout<<"Shutting movie threater down...\n";
		popper->off();
		lights->on();
		screen->up();
		projector->off();
		amp->off();
		dvd->stop();
		dvd->eject();
		dvd->off();
	}

};

#endif