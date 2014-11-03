//
//  Animal.h
//  MusicSequencer
//
//  Created by LaParure on 10/28/14.
//
//

#ifndef MusicSequencer_Animal_h
#define MusicSequencer_Animal_h
#include <string>
#include "ofMain.h"
class Animal {
public:
    std::string name;
    // Constructor
    Animal();
    Animal(std::string name);
    
    
    // Methods
    void moveTo();
    void draw();
    void setPos(float xPos,float yPos);
    void setDist(float x,float y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    bool operator = (const Animal & a) const{
        const Animal &b=*this;
        return a.name.compare(b.name);
    };
    bool operator < (const Animal & a) const{
        const Animal &b=*this;
        return a.name.compare(b.name);
    };
    // Properties
    float x;
    float y;
    ofImage img;
    ofSoundPlayer wav;
    float w;
    float h;
    int index;
    ofPoint dist;

};

#endif
