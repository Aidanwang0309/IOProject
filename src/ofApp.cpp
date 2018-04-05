#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetBackgroundAuto(false);
    ofBackground(255);
    
    timeScale = 100.0;
    clearAlpha = 0.5;
    
    prevx = prevy = degree = radian = x = y = 0.0f;
    amp = 50; // size of the rose
    x0 = y0 = 0; // this becomes the center
    petals = 6; // number of petals
    ofSetFrameRate(30);
}


//--------------------------------------------------------------
void ofApp::update(){

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // Reverse the contrast of the rectangles and screen over time
    ofColor darkColor(0,0,0,255);  // Opaque black
    ofColor lightColor(255,255,255,255);  // Opaque white
    float time = ofGetElapsedTimef();  // Time in seconds
    float percent = ofMap(cos(time/2.0), -1, 1, 0, 1);
    ofColor bgColor = darkColor;
    bgColor.lerp(lightColor, percent);
    bgColor.a = clearAlpha;
    ofColor fgColor = lightColor;
    fgColor.lerp(darkColor, percent);
    ofSetColor(bgColor);
    
    
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    // Draw the spiraling rectangles
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(255);
    ofNoFill();
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    for (int i=0; i<100; i++) {
        ofScale(1.1, 1.1);
        // Make the rectangles spiral
        float time = ofGetElapsedTimef();
        float noise = ofSignedNoise(time * timeScale) * 20.0;
        ofRotate(noise);
        if(pattern==1){
            patternGenerating(1);
        }
        else if(pattern==2){
            patternGenerating(2);
        }
        else if(pattern==3){
            patternGenerating(3);
        }
        else if(pattern==4){
            patternGenerating(4);
        }
        else if(pattern==5){
            patternGenerating(5);
        }
        else if(pattern==6){
            patternGenerating(6);
        }
            }
    ofPopMatrix();
}

//--------------------------------------------------------------

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if( key=='r'){
        //flip a boolean member variable
        pdfRendering = !pdfRendering;
        if( pdfRendering ){
            //play around with this number to determine the optimal number of pages for your needs
            ofSetFrameRate(12);  // so it doesn't generate tons of pages
            //ofGetTimestampString is another timestamp variable and it's formatted nicely for filenames
            ofBeginSaveScreenAsPDF("recording-"+ofGetTimestampString()+".pdf", true);
        }else{
            ofSetFrameRate(60);
            ofEndSaveScreenAsPDF();
        }
    }
    
    else if (key=='1'){
        pattern=1;
    }
    else if (key=='2'){
        pattern=2;
    }
    else if (key=='3'){
        pattern=3;
    }
    else if (key=='4'){
        pattern=4;
    }
    else if (key=='5'){
        pattern=5;
    }
    else if (key=='6'){
        pattern=6;
    }
}


void ofApp::patternGenerating(int x){
    
    if(x==1){
            ofSetPolyMode(OF_POLY_WINDING_NONZERO);
            ofBeginShape();
            ofVertex(10,35);
            ofVertex(-85,35);
            ofVertex(65,-75);
            ofVertex(5,100);
            ofVertex(-50,-75);
            ofEndShape();
    } else if (x==2){
            radian = PI/180*(degree);
            p = amp*cos(6*radian);
            x = x0+p*cos(radian);
            y = y0+p*sin(radian);
            ofDrawLine(prevx, prevy, x, y);
            prevx = x;
            prevy = y;
            degree++;
    } else if (x==3){
        ofDrawRectangle(0, 0, 50, 50);
    } else if (x==4){
        ofDrawTriangle(0, 20, 23, -20, -23, -20);
    } else if (x==5){
        ofDrawRectangle(-20, 20, 50, 50);
        ofDrawRectangle(20, 20, 50, 50);
        ofDrawRectangle(-20, -20, 50, 50);
        ofDrawRectangle(20, -20, 50, 50);
    }else if (x==6){
        ofDrawEllipse(20, 20, 50, 50);
        ofDrawEllipse(-20, -20, 50, 50);
        ofDrawEllipse(20, -20, 50, 50);
        ofDrawEllipse(-20, 20, 50, 50);
    }
    
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    clearAlpha = ofMap(x, 0, ofGetWidth(), 0, 255);
    timeScale = ofMap(y, 0, ofGetHeight(), 0, 1);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
