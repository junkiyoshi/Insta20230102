#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetColor(255);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	int size = 30;

	for (int x = size * -14; x <= size * 14; x += size) {

		for (int y = size * -14; y <= size * 14; y += size) {

			ofPushMatrix();
			ofTranslate(x, y);

			int param = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.003), 0, 1, 0, 4);

			switch (param) {
			case 0:

				ofDrawLine(size * -1, 0, 0, 0);
				ofDrawLine(0, 0, 0, size * -1);
				break;
			case 1:

				ofDrawLine(0, size * -1, 0, 0);
				ofDrawLine(0, 0, size * 1, 0);
				break;
			case 2:

				ofDrawLine(size * 1, 0, 0, 0);
				ofDrawLine(0, 0, 0, size * 1);
				break;
			case 3:

				ofDrawLine(0, size * 1, 0, 0);
				ofDrawLine(0, 0, -size * 1, 0);
				break;
			}

			ofPopMatrix();
		}
	}

}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}