

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetFrameRate(30);
	ofEnableAlphaBlending();
	ofNoFill();
    ofBackground(0);
    
    ofSetWindowShape(800, 800);
    
    shader.load("shaders/noise.vert", "shaders/noise.frag");
	
	//this slows down the rotate a little bit
	dampen = .4;
	
	// create little objects for each city. 
	// A Lat/Lon like this: 
	// Lewiston, Idaho 	W 46 24' N 117 2'
	// This translate to angles and degrees (1 degree = 1/60. of an angle)
	// West and South are negative values
	
	// here is a list of big cities and their positions
	// http://www.infoplease.com/ipa/A0001796.html
	
	City newyork = { "new york", 40+47/60., -73 + 58/60. };
	City tokyo = { "tokyo", 35 + 40./60, 139 + 45/60. };
	City london = { "london", 51 + 32/60., -5./60. };
	City shanghai = { "shanghai", 31 + 10/60., 121 + 28/60. };
	City buenosaires = { "buenos aires", -34 + 35/60., -58 + 22/60. };
	City melbourne = { "melbourne" , -37 + 47/60., 144 + 58/60. };	
	City detroit = { "detroit", 42 + 19/60., -83 + 2 / 60. };

	cities.push_back( newyork );
	cities.push_back( tokyo );
	cities.push_back( london );
	cities.push_back( shanghai );
	cities.push_back( buenosaires );
	cities.push_back( melbourne );
	cities.push_back( detroit );
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
    
                        /////////// SHADERRRRRRRRRRR
    shader.begin();
//    //we want to pass in some varrying values to animate our type / color
//    shader.setUniform1f("timeValX", ofGetElapsedTimef() * 0.1 );
//    shader.setUniform1f("timeValY", -ofGetElapsedTimef() * 0.18 );
//    
//    //we also pass in the mouse position
//    //we have to transform the coords to what the shader is expecting which is 0,0 in the center and y axis flipped.
//    shader.setUniform2f("mouse", mouseX - ofGetWidth()/2, ofGetHeight()/2-mouseY);

    shader.setUniform4f("orientation", curRot.w(), curRot.x(), curRot.y(), curRot.z());
                        /////////// SHADERRRRRRRRRRR
                        
                        
    
    
    
	ofBackground(0);
	ofSetColor(255, 255, 255, 20);
	
	
	//draw a translucent wireframe sphere (ofNoFill() is on)
	ofPushMatrix();

    //Extract the rotation from the current rotation
    ofVec3f axis;
    float angle;
    curRot.getRotate(angle, axis);
    

	ofSphere(0, 0, 0, 1);
	ofRotate(angle, axis.x, axis.y, axis.z);
	ofPopMatrix();
	
//	ofSetColor(255);	
//	for(int i = 0; i < cities.size(); i++){
//		
//		//three rotations
//		//two to represent the latitude and lontitude of the city
//		//a third so that it spins along with the spinning sphere 
//		ofQuaternion latRot, longRot, spinQuat;
//		latRot.makeRotate(cities[i].latitude, 1, 0, 0);
//		longRot.makeRotate(cities[i].longitude, 0, 1, 0);
//		spinQuat.makeRotate(angle, axis.x, axis.y, axis.z);
//		
//		//our starting point is 0,0, on the surface of our sphere, this is where the meridian and equator meet
//		ofVec3f center = ofVec3f(0,0,1);
//		//multiplying a quat with another quat combines their rotations into one quat
//		//multiplying a quat to a vector applies the quat's rotation to that vector
//		//so to to generate our point on the sphere, multiply all of our quaternions together then multiple the centery by the combined rotation
//		ofVec3f worldPoint = latRot * longRot * spinQuat * center;
//		
//		//draw it and label it
//		ofLine(ofVec3f(0,0,0), worldPoint);
//
//		//set the bitmap text mode billboard so the points show up correctly in 3d
//		ofDrawBitmapString(cities[i].name, worldPoint );
//	}
//	
//	ofPopMatrix();
    
                            /////////// SHADERRRRRRRRRRR
    shader.end();
    
                            /////////// SHADERRRRRRRRRRR
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
//    azeqsdd
    float da=360./32.;
    ofQuaternion rot;
    switch(key) {
        case 97:
            rot= ofQuaternion(da, ofVec3f(0,0,1));
            curRot *= rot;
            break;
        case 122:
            rot= ofQuaternion(da, ofVec3f(0,-1,0));
            curRot *= rot;
            break;
        case 101:
            rot= ofQuaternion(da, ofVec3f(0,0,-1));
            curRot *= rot;
            break;
        case 113:
            rot= ofQuaternion(da, ofVec3f(-1,0,0));
            curRot *= rot;
            break;
        case 115:
            rot= ofQuaternion(da, ofVec3f(0,1,0));
            curRot *= rot;
            break;
        case 100:
            rot= ofQuaternion(da, ofVec3f(1,0,0));
            curRot *= rot;
            break;
        default:
            break;
            
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
	//every time the mouse is dragged, track the change
	//accumulate the changes inside of curRot through multiplication
    ofVec2f mouse(x,y);
    ofQuaternion yRot((x-lastMouse.x)*dampen, ofVec3f(0,0,1));
    ofQuaternion xRot((y-lastMouse.y)*dampen, ofVec3f(0,1,0));
    curRot *= yRot*xRot;
    lastMouse = mouse;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    //store the last mouse point when it's first pressed to prevent popping
	lastMouse = ofVec2f(x,y);
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