#pragma once

#include "ofMain.h"

#include "ofxImGui.h"
#include "ofxTimelineLoader.h"

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

	struct TimelineData {
		std::shared_ptr<ofxTimelineLoader::Timeline> timeline;
		// for imgui
		float t = 0.0f;
		float x = 0.0f;
		float y = 0.0f;
		bool looped = true;
	} timelineData;
};
