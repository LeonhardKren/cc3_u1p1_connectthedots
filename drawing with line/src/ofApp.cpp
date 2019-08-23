#include "ofApp.h"

int rainx[20];
int rainspeed[20];
int rainy[20];
int dotsx[20];
int dotsy[20];
int transp=255;
//--------------------------------------------------------------
void ofApp::setup(){
    pts =0;
    for(int i=0; i<20;i++)
    {
        rainx[i]= rand()%1000+1;
        rainspeed[i]=rand()%5+1;
        rainy[i]=rand()%800+1;
        dotsx[i]=rand()%800+1;
        dotsy[i]=rand()%600+1;
        
    }
    image.load("dots.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,255,255);
    //image.draw(0,0);
    
    for(int i=0;i<20;i++)
    {
        ofSetColor(0, 0, 0);
        ofDrawCircle(dotsx[i], dotsy[i], 15);
        ofSetColor(255,255,255);
        ofDrawBitmapString(i+1, dotsx[i]-5, dotsy[i]);
        ofSetColor(255,0,0);
    ofDrawEllipse(rainx[i], rainy[i], 5, 10);
    rainy[i]=rainy[i]+rainspeed[i];
    if(rainy[i]>800)
    {
        rainy[i]=0;
        rainx[i]=rand()%1000+1;
    }
        
    }
    
    ofSetColor(0, 0, 255,transp);
   // transp-=5;
    if(pts>1)
    {
        for (int i=0; i<pts-1; i++) {
            ofLine(points[i].x,points[i].y,points[i+1].x,points[i+1].y);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    transp=255;
    pts=0;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
if(pts<maxpoints)
{
    points[pts].x=x;
    points[pts].y=y;
    pts++;
}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    transp=255;
 

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
