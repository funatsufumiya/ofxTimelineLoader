#include "ofApp.h"

#include "ofxEasing.h"
#include "ofxTimelineLoader.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();

    // --- XML文字列（本来はファイルから読む） ---
    std::string xml_x = R"(<keyframes>
    <key>
        <easefunc>0</easefunc>
        <easetype>0</easetype>
        <time>00:00:00:524</time>
        <value>0.375000000</value>
    </key>
    <key>
        <easefunc>0</easefunc>
        <easetype>0</easetype>
        <time>00:00:00:826</time>
        <value>0.408691406</value>
    </key>
    <key>
        <easefunc>0</easefunc>
        <easetype>0</easetype>
        <time>00:00:01:034</time>
        <value>0.324999988</value>
    </key>
    <key>
        <easefunc>0</easefunc>
        <easetype>0</easetype>
        <time>00:00:01:459</time>
        <value>0.777343750</value>
    </key>
    <key>
        <easefunc>4</easefunc>
        <easetype>0</easetype>
        <time>00:00:02:123</time>
        <value>0.330175757</value>
    </key>
</keyframes>)";

    std::string xml_y = R"(<keyframes>
    <key>
        <easefunc>0</easefunc>
        <easetype>0</easetype>
        <time>00:00:00:643</time>
        <value>0.585546851</value>
    </key>
    <key>
        <easefunc>4</easefunc>
        <easetype>2</easetype>
        <time>00:00:00:826</time>
        <value>0.141503930</value>
    </key>
    <key>
        <easefunc>1</easefunc>
        <easetype>1</easetype>
        <time>00:00:01:594</time>
        <value>0.443359375</value>
    </key>
    <key>
        <easefunc>0</easefunc>
        <easetype>2</easetype>
        <time>00:00:02:033</time>
        <value>0.400390625</value>
    </key>
    <key>
        <easefunc>4</easefunc>
        <easetype>0</easetype>
        <time>00:00:02:260</time>
        <value>0.586718738</value>
    </key>
</keyframes>)";

    using namespace ofxTimelineLoader;
    timelineData.timeline = std::make_shared<Timeline>();
    timelineData.timeline->add<float>("x", track_from_xml<float>(xml_x));
    timelineData.timeline->add<float>("y", track_from_xml<float>(xml_y));

    timelineData.t = 0.0f;
    timelineData.x = 0.0f;
    timelineData.y = 0.0f;
    timelineData.looped = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    if (!timelineData.timeline) return;
    float maxDuration = float(timelineData.timeline->get_max_duration().count()) / 1000.0f;
    timelineData.t += ofGetLastFrameTime();
    if (timelineData.looped && timelineData.t > maxDuration) {
        timelineData.t = 0.0f;
    }
    float t_ms = timelineData.t * 1000.0f;
    try {
        timelineData.x = timelineData.timeline->get_value<float>("x", std::chrono::milliseconds((int)t_ms));
        timelineData.y = timelineData.timeline->get_value<float>("y", std::chrono::milliseconds((int)t_ms));
    } catch (...) {
        timelineData.x = 0.0f;
        timelineData.y = 0.0f;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // 描画パラメータ
    float length = 400.0f;
    float height = 100.0f;
    float x = timelineData.x * length - length / 2.0f + ofGetWidth() / 2.0f;
    float y = timelineData.y * height + ofGetHeight() / 2.0f;

    // ベースライン
    float ny = ofGetHeight() / 2.0f - 60.0f;
    ofSetColor(ofColor::green);
    ofDrawLine(ofGetWidth() / 2.0f - length / 2.0f, ny, ofGetWidth() / 2.0f + length / 2.0f, ny);
    ofDrawLine(ofGetWidth() / 2.0f - length / 2.0f, ny - 10.0f, ofGetWidth() / 2.0f - length / 2.0f, ny + 10.0f);
    ofDrawLine(ofGetWidth() / 2.0f + length / 2.0f, ny - 10.0f, ofGetWidth() / 2.0f + length / 2.0f, ny + 10.0f);

    // 円
    ofSetColor(ofColor::red);
    ofDrawCircle(x, y, 30.0f);

    // ImGui
    gui.begin();
    if(ImGui::Begin("Easing")){
        ImGui::SliderFloat("t", &timelineData.t, 0.0f, float(timelineData.timeline->get_max_duration().count()) / 1000.0f);
        ImGui::SliderFloat("x", &timelineData.x, 0.0f, 1.0f);
        ImGui::SliderFloat("y", &timelineData.y, 0.0f, 1.0f);
        ImGui::Checkbox("looped", &timelineData.looped);
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
