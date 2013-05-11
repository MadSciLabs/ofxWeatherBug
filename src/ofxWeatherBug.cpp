//
//  ofxWeatherBug.cpp
//  OFX_WEATHERBUG
//
//  Created by Rui Pereira (rux) for MadSci-Lab @HAVAS on 5/7/13.
//
//

#include "ofxWeatherBug.h"
#include "Poco/RegularExpression.h"
using Poco::RegularExpression;

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
void ofxWeatherBug::setup(string _apiKEY, string _zipCODE, bool _useMetricCentigrade){
    startTIME = ofGetElapsedTimeMillis();
    URL = "http://api.wxbug.net/getLiveWeatherRSS.aspx?ACode=" + _apiKEY +"&zipcode="+ _zipCODE +"&unittype="+ ofToString(_useMetricCentigrade);


}


// - - - - - - - - - - - - - - - - - - - - - - - - - - -
wData ofxWeatherBug::getWeather(){
    wData DATA;
    
    ofHttpResponse response = ofLoadURL(URL);
    if (response.status == 200) {
        string rawDATA = response.data.getText();
        //        cout<< rawDATA <<endl;
        
        //                                                                                                  temperature
        RegularExpression regEXTemperature("<aws:temp units=(.*?)</aws:temp>");
        RegularExpression::Match matchTemperature;
        int foundT = regEXTemperature.match(rawDATA, matchTemperature);
        
        if (foundT!=0) {
            string content = rawDATA.substr(matchTemperature.offset, matchTemperature.length);
            string contentFirst = ofSplitString(content, ">")[1];
            string contentTemperature = ofSplitString(contentFirst, "<")[0];
            DATA.temperature = ofToInt(contentTemperature);
//            cout<< "temperature "<<DATA.temperature <<endl;

        }
        
        //                                                                                                  wind-speed
        RegularExpression regEXWSpeed("<aws:wind-speed units=(.*?)</aws:wind-speed>");
        RegularExpression::Match matchWSpeed;
        int foundWSpeed = regEXWSpeed.match(rawDATA, matchWSpeed);
        
        if (foundWSpeed != 0) {
            string content = rawDATA.substr(matchWSpeed.offset, matchWSpeed.length);
            string contentFirst = ofSplitString(content, ">")[1];
            string contentWSpeed = ofSplitString(contentFirst, "<")[0];
            DATA.windSpeed = ofToInt(contentWSpeed);
//            cout<< "wind-speed "<<DATA.windSpeed <<endl;

        }
        
        //                                                                                                  wind-direction
        RegularExpression regEXWDir("<aws:wind-direction-degrees>(.*?)</aws:wind-direction-degrees>");
        RegularExpression::Match matchWDir;
        int foundWDir = regEXWDir.match(rawDATA, matchWDir);
        
        if (foundWDir != 0) {
            string content = rawDATA.substr(matchWDir.offset, matchWDir.length);
            string contentFirst = ofSplitString(content, ">")[1];
            string contentWDir = ofSplitString(contentFirst, "<")[0];
            DATA.windDirection = ofToInt(contentWDir);
//            cout<< "wind-dir "<<DATA.windDirection <<endl;
        }
        
        //                                                                                                  wind-direction NSEW
        RegularExpression regEXWNSEW("<aws:wind-direction>(.*?)</aws:wind-direction>");
        RegularExpression::Match matchWNSEW;
        int foundWNSEW = regEXWNSEW.match(rawDATA, matchWNSEW);
        
        if (foundWNSEW != 0) {
            string content = rawDATA.substr(matchWNSEW.offset, matchWNSEW.length);
            string contentFirst = ofSplitString(content, ">")[1];
            string contentWNSEW = ofSplitString(contentFirst, "<")[0];
            DATA.windCardinals = contentWNSEW;
//            cout<< "wind-dir NSEW "<<DATA.windCardinals <<endl;

        }
        
        //                                                                                                  rain in inches
        RegularExpression regEXRain("<aws:rain-today units=(.*?)</aws:rain-today>");
        
        RegularExpression::Match matchRain;
        int foundRain = regEXRain.match(rawDATA, matchRain);
        
        if (foundRain != 0) {
            string content = rawDATA.substr(matchRain.offset, matchRain.length);
            string contentFirst = ofSplitString(content, ">")[1];
            string contentRain = ofSplitString(contentFirst, "<")[0];
            DATA.rainAmount = ofToFloat(contentRain);
//            cout<< "rain \" "<<DATA.rainAmount <<endl;

        }
        
        //                                                                                                  condition
        RegularExpression regEXCondition("<aws:current-condition icon=(.*?)</aws:current-condition>");
        
        RegularExpression::Match matchCondition;
        int foundCondition = regEXCondition.match(rawDATA, matchCondition);
        
        if (foundCondition != 0) {
            string content = rawDATA.substr(matchCondition.offset, matchCondition.length);
            string contentFirst = ofSplitString(content, ">")[1];
            string contentCondition = ofSplitString(contentFirst, "<")[0];
            DATA.condition = contentCondition;
//            cout<< "condition "<<DATA.condition <<endl;
            
        }

        //                                                                                                  humidity
        RegularExpression regEXHumidity("<aws:humidity units=(.*?)</aws:humidity>");
        
        RegularExpression::Match matchHumidity;
        int foundHumidity = regEXHumidity.match(rawDATA, matchHumidity);
        
        if (foundHumidity != 0) {
            string content = rawDATA.substr(matchHumidity.offset, matchHumidity.length);
            string contentFirst = ofSplitString(content, ">")[1];
            string contentHumidity = ofSplitString(contentFirst, "<")[0];
            DATA.humidity = ofToFloat(contentHumidity);
//            cout<< "humidity "<<DATA.humidity <<endl;
            
        }
        
        //                                                                                                  light
        RegularExpression regEXLight("<aws:light>(.*?)</aws:light>");
        
        RegularExpression::Match matchLight;
        int foundLight = regEXLight.match(rawDATA, matchLight);
        
        if (foundLight != 0) {
            string content = rawDATA.substr(matchLight.offset, matchLight.length);
            string contentFirst = ofSplitString(content, ">")[1];
            string contentLight = ofSplitString(contentFirst, "<")[0];
            DATA.light = ofToFloat(contentLight);
//            cout<< "light "<<DATA.light <<endl;
            
        }

        //                                                                                                  pressure
        RegularExpression regEXPressure("<aws:pressure units=(.*?)</aws:pressure>");
        
        RegularExpression::Match matchPressure;
        int foundPressure = regEXPressure.match(rawDATA, matchPressure);
        
        if (foundPressure != 0) {
            string content = rawDATA.substr(matchPressure.offset, matchPressure.length);
            string contentFirst = ofSplitString(content, ">")[1];
            string contentPressure = ofSplitString(contentFirst, "<")[0];
            DATA.pressure = ofToFloat(contentPressure);
//            cout<< "pressure "<<DATA.pressure <<endl;
            
        }
        
        //                                                                                                  condition IMG
        RegularExpression regEXConditionIMG("<aws:current-condition icon=(.*?)</aws:current-condition>");
        
        RegularExpression::Match matchConditionIMG;
        int foundConditionIMG = regEXConditionIMG.match(rawDATA, matchConditionIMG);
        
        if (foundConditionIMG != 0) {
            string content = rawDATA.substr(matchConditionIMG.offset, matchConditionIMG.length);
            string conditionIMG = ofSplitString(content, "\"")[1];
            ofStringReplace(conditionIMG, ".gif", ".png");

            ofStringReplace(conditionIMG, "http://deskwx.weatherbug.com/images/Forecast/icons/", "http://img.weather.weatherbug.com/forecast/icons/localized/50x42/en/trans/");
            ofStringReplace(conditionIMG, ".gif", ".png");
//            cout << conditionIMG <<endl;
            
            if (!DATA.conditionIMG.loadImage(conditionIMG)) {
                ofLog(OF_LOG_ERROR, "something went wrong.. no IMG, no fun!");
            }
            
            
        }

        //                                                                                                  moonPhase IMG
        RegularExpression regEXMoonIMG("<aws:moon-phase moon-phase-img=(.*?)</aws:moon-phase>");
        
        RegularExpression::Match matchMoonIMG;
        int foundMoonIMG = regEXMoonIMG.match(rawDATA, matchMoonIMG);
        
        if (foundMoonIMG != 0) {
            string content = rawDATA.substr(matchMoonIMG.offset, matchMoonIMG.length);
            string moonIMG = ofSplitString(content, "\"")[1];
//            cout << moonIMG <<endl;
            if (!DATA.moonPhaseIMG.loadImage(moonIMG)) {
                ofLog(OF_LOG_ERROR, "something went wrong.. no IMG, no fun!");
            }
        }
    
    }
    
    return DATA;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
wData ofxWeatherBug::update(int _intervalTIME){
    
    
    if (ofGetElapsedTimeMillis() - startTIME > _intervalTIME) {
        DATA = getWeather();
        startTIME = ofGetElapsedTimeMillis();
    }
    
    return DATA;
}

