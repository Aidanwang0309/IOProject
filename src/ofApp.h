#pragma once

#include "ofMain.h"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    void patternGenerating(int x);
    bool pdfRendering = false;

    float prevx, prevy, degree, radian, x, y, p;
    int amp, x0,y0, petals;
    int i=0;
    int j = 0;
    
    float timeScale;
    float clearAlpha;
    int pattern;
};
