#pragma once

#include "ofMain.h"
#include "Arrow.h"
#include "Animal.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        float xPos;
        float yPos;
        float xOne;
        float yOne;
        ofImage bg;
        ofImage tl;
        ofImage grass;
        ofImage fixed;
        ofImage play;
        ofImage one;
        ofPoint dist;
        ofSoundPlayer bm;
        vector<Animal> animals;
        Animal cat=Animal("cat");
        Animal dog=Animal("dog");
        Animal peacock=Animal("peacock");
        Animal hawk=Animal("hawk");
        Animal bear=Animal("bear");
        Animal horse=Animal("horse");
        Animal monkey=Animal("monkey");
        bool started;
        bool set;
        Arrow  arr=Arrow();
        vector<int> scale;
		
};
