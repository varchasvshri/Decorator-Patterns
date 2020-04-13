#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Observer
{
public:
	virtual ~Observer() = default;
	virtual void update(float temp, float humidity, float pressure){};
};

class Subject
{
public:
	virtual ~Subject() = default;
	virtual void registerObserver(Observer* o){};
	virtual void removeObserver(Observer* o){};
	virtual void notifyObservers(){};
};

class DisplayElement
{
public:
	virtual void display(){};
};

class WeatherData : public Subject
{
	vector<Observer*> observers;
	float temperature;
	float humidity;
	float pressure;
public:
	void registerObserver(Observer* o)
	{
		observers.push_back(o);
	}

	void removeObserver(Observer* o)	
	{
		for(auto beg = observers.begin(); beg < observers.end(); beg++)
		{
		    if(*beg == o)
		      beg = observers.erase(beg);
		}
	}

	void notifyObservers()
	{
		for(auto observer : observers)
		{
			observer->update(temperature, humidity, pressure);
		}
	}

	void measurementChanged(){
		notifyObservers();
	}

	void setMeasurements(float temperature,  float humidity, float pressure){
		this->temperature = temperature;
		this->humidity = humidity;
		this->pressure = pressure;
		measurementChanged();
	}
};

class  CurrentConditionsDisplay : public Observer, public DisplayElement{
	float temperature;
    float humidity;
    float pressure;
    Subject& weatherData;
public:
    CurrentConditionsDisplay(Subject &inWeatherData):temperature(0.0f),humidity(0.0f),pressure(0.0f),weatherData(inWeatherData)
    {
    	weatherData.registerObserver(this);
    }
    ~CurrentConditionsDisplay(){
    	weatherData.removeObserver(this);
    }

    void update(float temp, float hum, float press){
    	temperature = temp;
    	humidity = hum;
    	pressure = press;
    	display();
    }
    void display()
    {
    	cout<<"Current conditions: " << temperature << "F degrees, " << humidity << "% humidity and Atmospheric Pressure " << pressure<<" mmHg"<<endl;
    }
};

int main()
{
	WeatherData weatherData;
	CurrentConditionsDisplay currDisplay(weatherData);
	weatherData.setMeasurements(80, 65, 734);
  	weatherData.setMeasurements(82, 70, 736);
  	weatherData.setMeasurements(78, 90, 743);
	return 0;
}