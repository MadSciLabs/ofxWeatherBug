#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255);
    ofEnableAlphaBlending();
    
    bUnitsMetric = false;
    
    // setup the bugWeather object
    bug.setup("YOU_API_KEY", "ZIP_CODE", bUnitsMetric);

    
    // this is one way you can make requests and get the data parsed
    
    DATA = bug.getWeather();

    // load font sets

    med.loadFont("NeoSansIntel.ttf", 24);
    light.loadFont("NeoSansIntel-Light.ttf", 24);
    smallLight.loadFont("NeoSansIntel-Light.ttf", 14);
}

//--------------------------------------------------------------
void testApp::update(){
    
    // if you want to get the weather data periodically you can use this update function instead - interval times are set in milliseconds 
    wData DATA =  bug.update(10000);

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackgroundGradient(100, 20, OF_GRADIENT_LINEAR);
    
    ofSetColor(255);
    
    light.drawString("Today's condition", 20, 60);
    med.drawString(ofToString(DATA.condition), 20, 100);
    DATA.conditionIMG.draw(265, 35, DATA.conditionIMG.width*1.5, DATA.conditionIMG.height*1.5 );

    
    light.drawString("Temperature", 20, 160);
    if (bUnitsMetric) smallLight.drawString("C", 260+10+ med.getStringBoundingBox(ofToString(DATA.temperature),260, 150).width,150);
    else smallLight.drawString("F", 260+10+ med.getStringBoundingBox(ofToString(DATA.temperature),260, 150).width,150);
    med.drawString(ofToString(DATA.temperature), 260, 160);
    
    light.drawString("Humidity", 20, 200);
    med.drawString(ofToString(DATA.humidity), 260, 200);
    smallLight.drawString("%", 260+10+med.getStringBoundingBox(ofToString(DATA.humidity),260, 190).width, 190);
    
    light.drawString("Rain \"", 20, 240);
    if (bUnitsMetric) smallLight.drawString("mm", 260+10+ med.getStringBoundingBox(ofToString(DATA.rainAmount),260, 230).width,230);
    else smallLight.drawString("\"", 260+10+ med.getStringBoundingBox(ofToString(DATA.rainAmount),260, 230).width,230);
    med.drawString(ofToString(DATA.rainAmount), 260, 240);
    
    light.drawString("Wind Speed", 20, 280);
    if (bUnitsMetric) smallLight.drawString("Kmh", 260+10+ med.getStringBoundingBox(ofToString(DATA.windSpeed),260, 270).width,270);
    else smallLight.drawString("Mph", 260+10+ med.getStringBoundingBox(ofToString(DATA.windSpeed),260, 270).width,270);
    med.drawString(ofToString(DATA.windSpeed), 260, 280);
    
    light.drawString("Wind Direction", 20, 320);
    med.drawString(ofToString(DATA.windCardinals), 260, 320);
    
    light.drawString("Pressure", 20, 360);
    if (bUnitsMetric) smallLight.drawString("mb", 260+10+ med.getStringBoundingBox(ofToString(DATA.pressure),260, 350).width,350);
    else smallLight.drawString("\"", 260+10+ med.getStringBoundingBox(ofToString(DATA.pressure),260, 350).width,350);
    med.drawString(ofToString(DATA.pressure), 260, 360);
    
    light.drawString("Light", 20, 400);
    med.drawString(ofToString(DATA.light), 260, 400);
    
    light.drawString("Moon Phase", 20, 460);
    DATA.moonPhaseIMG.draw(260, 430, DATA.moonPhaseIMG.width*2, DATA.moonPhaseIMG.height*2);

    
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}