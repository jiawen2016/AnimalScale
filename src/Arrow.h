//
//  Arrow.h
//  MusicSequencer
//
//  Created by LaParure on 10/28/14.
//
//

#ifndef __MusicSequencer__Arrow__
#define __MusicSequencer__Arrow__

#include <stdio.h>
#include "ofMain.h"
class Arrow{
public:
    // Constructor
    Arrow();
    
    // Methods
    void moveTo();
    void draw();
    
    // Properties
    int xStart, xEnd;
    int yStart,yEnd;
    ofVec3f start;
    ofVec3f end;
    ofColor color;
};
#endif /* defined(__MusicSequencer__Arrow__) */
