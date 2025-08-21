#pragma once

#include "ofMain.h"

#include "ofxImGui.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxImGui::Gui gui;

		float t = 0.0f, v = 0.0f;
		bool goAndBack = false;
		int easingFuncIdx = 0, easingTypeIdx = 0;
		vector<std::string> funcNames;
		vector<std::string> typeNames;
};
