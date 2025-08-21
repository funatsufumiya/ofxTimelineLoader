#include "ofApp.h"

#include "ofxEasing.h"
#include "ofxTimelineLoader.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();

    using namespace ofxTimelineLoader;
    timeline = std::make_shared<Timeline>();

    Track<float> tx;
    tx.keyframes.push_back({std::chrono::milliseconds(0), 0.0f, ofxeasing::Function::Cubic, ofxeasing::Type::In});
    tx.keyframes.push_back({std::chrono::milliseconds(1000), 1.0f, ofxeasing::Function::Cubic, ofxeasing::Type::Out});
    tx.keyframes.push_back({std::chrono::milliseconds(2000), 0.0f, ofxeasing::Function::Cubic, ofxeasing::Type::In});
    timeline->add<float>("x", tx);

    Track<float> ty;
    ty.keyframes.push_back({std::chrono::milliseconds(0), 0.0f, ofxeasing::Function::Cubic, ofxeasing::Type::Out});
    ty.keyframes.push_back({std::chrono::milliseconds(500), 1.0f, ofxeasing::Function::Cubic, ofxeasing::Type::In});
    ty.keyframes.push_back({std::chrono::milliseconds(1000), 0.0f, ofxeasing::Function::Cubic, ofxeasing::Type::Out});
    ty.keyframes.push_back({std::chrono::milliseconds(1500), 1.0f, ofxeasing::Function::Cubic, ofxeasing::Type::Out});
    ty.keyframes.push_back({std::chrono::milliseconds(2000), 0.0f, ofxeasing::Function::Cubic, ofxeasing::Type::In});
    ty.keyframes.push_back({std::chrono::milliseconds(2500), 1.0f, ofxeasing::Function::Cubic, ofxeasing::Type::In});
    timeline->add<float>("y", ty);
}

//--------------------------------------------------------------
void ofApp::update(){
    if (!timeline) return;
    float maxDuration = float(timeline->get_max_duration().count()) / 1000.0f;
    t += ofGetLastFrameTime();
    if (looped && t > maxDuration) {
        t = 0.0f;
    }
    float t_ms = t * 1000.0f;
    try {
        x = timeline->get_value<float>("x", std::chrono::milliseconds((int)t_ms));
        y = timeline->get_value<float>("y", std::chrono::milliseconds((int)t_ms));
    } catch (...) {
        x = 0.0f;
        y = 0.0f;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    float length = 400.0f;
    float height = 100.0f;
    float _x = x * length - length / 2.0f + ofGetWidth() / 2.0f;
    float _y = y * height + ofGetHeight() / 2.0f;

    float ny = ofGetHeight() / 2.0f - 60.0f;
    ofSetColor(ofColor::green);
    ofDrawLine(ofGetWidth() / 2.0f - length / 2.0f, ny, ofGetWidth() / 2.0f + length / 2.0f, ny);
    ofDrawLine(ofGetWidth() / 2.0f - length / 2.0f, ny - 10.0f, ofGetWidth() / 2.0f - length / 2.0f, ny + 10.0f);
    ofDrawLine(ofGetWidth() / 2.0f + length / 2.0f, ny - 10.0f, ofGetWidth() / 2.0f + length / 2.0f, ny + 10.0f);

    ofSetColor(ofColor::red);
    ofDrawCircle(_x, _y, 30.0f);

    gui.begin();
    if(ImGui::Begin("Easing")){
        ImGui::SliderFloat("t", &t, 0.0f, float(timeline->get_max_duration().count()) / 1000.0f);
        ImGui::SliderFloat("x", &x, 0.0f, 1.0f);
        ImGui::SliderFloat("y", &y, 0.0f, 1.0f);
        ImGui::Checkbox("looped", &looped);
    }
    ImGui::End();
    gui.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
