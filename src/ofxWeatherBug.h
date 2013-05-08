//
//  ofxWeatherBug.h
//  OFX_WEATHERBUG
//
//  Created by Rui Pereira (rux) for MadSci-Lab @HAVAS on 5/7/13.
//
//
// this a quick and dirty to get and parse data from the weatherBug API in XML.
// get your API Key = http://weather.weatherbug.com/desktop-weather/api.html
// data structure should be self-explanatory and enough for basic weather analisys but feel free to parse more!

#ifndef _ofxWeatherBug
#define _ofxWeatherBug

#include "ofMain.h"

struct wData {
    float temperature;
    float windSpeed;
    float windDirection;
    string windCardinals;
    float rainAmount;
    string condition;
    float humidity;
    float light;
    float pressure;
    ofImage moonPhaseIMG;
    ofImage conditionIMG;
};

class ofxWeatherBug{
    
public:
    
    void setup(string _apiKEY, string _zipCODE, bool _useMetricCentigrade);
    
    wData update(int _intervalTIME);
    
    wData getWeather();
    
    int startTIME;
    string URL;
    wData DATA;

};
#endif