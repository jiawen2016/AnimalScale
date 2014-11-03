#include "ofApp.h"
#include "Arrow.h"
#include "Animal.h"
#include <math.h>

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("AnimalScale");
    // load background image
    bg.loadImage("bg.jpg");
    bg.resize(ofGetWindowWidth(), ofGetWindowHeight());
    tl.loadImage("title.png");
    one.loadImage("scale.png");
    one.resize(ofGetWindowWidth(), ofGetWindowHeight()*0.3);
    tl.resize(ofGetWindowWidth()*0.4, ofGetWindowHeight()*0.4);
    bm.loadSound("grass.mp3");
    grass.loadImage("set.png");
    grass.resize(180,100);
    fixed.loadImage("fixed.png");
    fixed.resize(220,100);
    play.loadImage("play.png");
    play.resize(100,100);
    // Smooth edges
    ofEnableSmoothing();
    
    // Fixed framerate
    ofSetFrameRate(30);
    animals.push_back(cat);
    animals.push_back(dog);
    animals.push_back(peacock);
    animals.push_back(hawk);
    animals.push_back(bear);
    animals.push_back(horse);
    animals.push_back(monkey);
    int j=0;
    for (int i=0;i<animals.size();i++) {
        animals[i].setPos(ofGetWindowWidth()/7*i,ofGetWindowHeight()*0.05*(4-i%3));
        
    }
    xOne = 0;
    yOne = ofGetWindowHeight()*0.5;
    started=false;
    set=true;
    for(int i=0;i<7;i++){
        scale.push_back(-1);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0;i<animals.size();i++){
    if(animals[i].x >= ofGetWindowWidth()-animals[i].w)
    {
        animals[i].x = ofGetWindowWidth()-animals[i].w;
    }
    if(animals[i].x <= 0)
    {
        animals[i].x = 0;
    }
    if(animals[i].y >= ofGetWindowHeight()-animals[i].h)
    {
        animals[i].y = ofGetWindowHeight()-animals[i].h;
    }
    if(animals[i].y <= 0)
    {
        animals[i].y = 0;
    }
    }
    if(started&&!bm.getIsPlaying())
        bm.play();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    bg.draw(0, 0);
    tl.draw(ofGetWindowWidth()*0.3, ofGetWindowHeight()*0.1);
    grass.draw(0,ofGetWindowHeight()*0.8);
    fixed.draw(400,ofGetWindowHeight()*0.8);
    play.draw(800,ofGetWindowHeight()*0.8);
    one.draw(xOne, yOne);
    for (int i=0;i<animals.size();i++) {
        animals[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(started){
    if(key=='1'){
        animals[scale[0]].wav.play();
    }
    else if(key=='2'){
        animals[scale[1]].wav.play();
    }
    else if(key=='3'){
        animals[scale[2]].wav.play();
    }
    else if(key=='4'){
        animals[scale[3]].wav.play();
    }
    else if(key=='5'){
        animals[scale[4]].wav.play();
    }
    else if(key=='6'){
        animals[scale[5]].wav.play();
    }
    else if(key=='7'){
        animals[scale[6]].wav.play();
    }
    }

}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
   
}

//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(!set){
    
    for(int i=0;i<animals.size();i++){
        if(x>=animals[i].x&&x<=animals[i].x+animals[i].w&&y>=animals[i].y&&y<=animals[i].y+animals[i].h){
            animals[i].setPos(mouseX-animals[i].dist.x,mouseY-animals[i].dist.y);
            draw();
            return;
        }
    }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(x>=0&&x<=grass.getWidth()&&y>=ofGetWindowHeight()*0.8&&y<=grass.getHeight()+ofGetWindowHeight()*0.8){
        
        set=false;
    }
    else if(x>=400&&x<=fixed.getWidth()+400&&y>=ofGetWindowHeight()*0.8&&y<=fixed.getHeight()+ofGetWindowHeight()*0.8){
        
        set=true;
    }
    else if(x>=800&&x<=fixed.getWidth()+800&&y>=ofGetWindowHeight()*0.8&&y<=fixed.getHeight()+ofGetWindowHeight()*0.8){
        
        started=true;
        bm.play();
    }
    else{
        for(int i=0;i<animals.size();i++){
            if(x>=animals[i].x&&x<=animals[i].x+animals[i].w&&y>=animals[i].y&&y<=animals[i].y+animals[i].h){
                animals[i].setDist(mouseX-animals[i].x,mouseY-animals[i].y);
                return;
            }
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    for(int i=0;i<animals.size();i++){
        if(x>=animals[i].x&&x<=animals[i].x+animals[i].w&&y>=animals[i].y&&y<=animals[i].y+animals[i].h){
            if(scale[animals[i].index]!=-1){
                
                scale[animals[i].index]=-1;
            }
            int index=x/(ofGetWindowWidth()/7);
            if(y>yOne&&y<=yOne+one.getHeight()){
                scale[index]=i;
                animals[i].index=index;
               
                if(!set){
                for(int j=0;j<7;j++){
                    if(scale[j]!=-1){
                        animals[scale[j]].wav.play();
                        
                        while(animals[scale[j]].wav.getIsPlaying()){
                        
                        }
                    }
                }}
                else
                    animals[i].wav.play();
            
            }
            return;
        }
    
    }
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
