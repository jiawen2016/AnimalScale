//
//  Arrow.cpp
//  MusicSequencer
//
//  Created by LaParure on 10/28/14.
//
//

#include "Arrow.h"
Arrow::Arrow(){
    // Set the initial color
    color.set( ofRandom(255), ofRandom(255), ofRandom(255));
    
    // Initial x position of the ball
    //xStart = ofRandom( ofGetWindowWidth() );
    
    // Initial y position of the ball
    //yStart = ofRandom( ofGetWindowHeight() );
}

void Arrow::moveTo(){
    
}

void Arrow::draw(){
    //ofSetColor(color);
    //ofFill();
    
    start.set(xStart,yStart,0);
    end.set(xStart,yEnd,0);
    ofDrawArrow(start,end,10);
    cout<<xStart<<"START"<<yStart<<endl;
    cout<<xEnd<<"End"<<yEnd<<endl;
}
