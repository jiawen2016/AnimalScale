//
//  Animal.cpp
//  MusicSequencer
//
//  Created by LaParure on 10/28/14.
//
//

#include "Animal.h"
#include <string>
Animal::Animal(std::string str){
    // Set the initial color
    name=str;
    img.loadImage(name+".png");
    img.resize(ofGetWindowWidth()/7,ofGetWindowWidth()/7);
    w=img.getWidth();
    h=img.getHeight();
    wav.loadSound(name+".wav");
    index=-1;
}

void Animal::draw(){
    
    img.draw(x,y);

    
}
void Animal::setPos(float xPos,float yPos){
    x=xPos;
    y=yPos;
}
void Animal::setDist(float x,float y){
    dist.x=x;
    dist.y=y;
}
