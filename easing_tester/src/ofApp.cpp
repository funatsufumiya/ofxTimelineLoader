#include "ofApp.h"

#include "ofxEasing.h"

#include <array>

static const std::array<ofxeasing::Function, 11> funcEnums = {
    ofxeasing::Function::Linear,
    ofxeasing::Function::Sine,
    ofxeasing::Function::Circular,
    ofxeasing::Function::Quadratic,
    ofxeasing::Function::Cubic,
    ofxeasing::Function::Quartic,
    ofxeasing::Function::Quintic,
    ofxeasing::Function::Exponential,
    ofxeasing::Function::Back,
    ofxeasing::Function::Bounce,
    ofxeasing::Function::Elastic
};
static const std::array<ofxeasing::Type, 3> typeEnums = {
    ofxeasing::Type::In,
    ofxeasing::Type::Out,
    ofxeasing::Type::InOut
};

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    funcNames = {"Linear", "Sine", "Circular", "Quadratic", "Cubic", "Quartic", "Quintic", "Exponential", "Back", "Bounce", "Elastic"};
    typeNames = {"In", "Out", "InOut"};
    t = 0.0f;
    v = 0.0f;
    goAndBack = false;
    easingFuncIdx = 0;
    easingTypeIdx = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    float duration = 1.0f;
    float time = ofGetElapsedTimef();
    if(goAndBack){
        float s = fmod(time, duration * 2.0f);
        t = (s > duration) ? (2.0f * duration - s) : s;
    }else{
        t = fmod(time, duration);
    }

    v = ofxeasing::easing(funcEnums[easingFuncIdx], typeEnums[easingTypeIdx])(t, 0.0f, 1.0f, duration);
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.begin();
    if(ImGui::Begin("Easing Tester")){
        ImGui::Checkbox("Go and back", &goAndBack);
        ImGui::SliderFloat("t", &t, 0.0f, 1.0f);
        ImGui::SliderFloat("v", &v, 0.0f, 1.0f);
        std::vector<const char*> funcNamePtrs;
        for(const auto& s : funcNames) funcNamePtrs.push_back(s.c_str());
        ImGui::Combo("Function", &easingFuncIdx, funcNamePtrs.data(), funcNames.size());
        std::vector<const char*> typeNamePtrs;
        for(const auto& s : typeNames) typeNamePtrs.push_back(s.c_str());
        ImGui::Combo("Type", &easingTypeIdx, typeNamePtrs.data(), typeNames.size());
    }
    ImGui::End();
    gui.end();

    float length = 200.0f;
    float x = v * length - length / 2.0f;
    float y = 0.0f;
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

    ofSetColor(ofColor::red);
    ofDrawCircle(x, y, 30.0f);

    float ny = -60.0f;
    ofSetColor(ofColor::green);
    ofDrawLine(-length/2, ny, length/2, ny);
    ofDrawLine(-length/2, ny-10, -length/2, ny+10);
    ofDrawLine(length/2, ny-10, length/2, ny+10);

    ofPopMatrix();
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