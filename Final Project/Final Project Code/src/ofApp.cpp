#include "ofApp.h"

using namespace glm;
//--------------------------------------------------------------
void ofApp::setup(){

    // plane
	quad.addVertex(vec3(-1, -1, 0));
	quad.addVertex(vec3(-1, 1, 0));
	quad.addVertex(vec3(1, 1, 0));
	quad.addVertex(vec3(1, -1, 0));

	quad.addColor(ofDefaultColorType(1, 0, 0, 1));
	quad.addColor(ofDefaultColorType(0, 1, 0, 1));
	quad.addColor(ofDefaultColorType(0, 0, 1, 1));
	quad.addColor(ofDefaultColorType(1, 1, 1, 1));

	quad.addTexCoord(vec2(-1, -1));
	quad.addTexCoord(vec2(-1, 1));
	quad.addTexCoord(vec2(1, 1));
	quad.addTexCoord(vec2(1, -1));

	ofIndexType indices[6] = { 0,1,2,2,3,0 };
	quad.addIndices(indices, 6);

	ofDisableArbTex();
	ofEnableDepthTest();
    GL_NEAREST;

	shader.load("shader.vert", "shader.frag");
	texture.load("texture/rgb.png");

    cam.setPosition(vec3(0, 0, 1));
    cam.setFov(radians(100.0f));
}


void ofApp::updateCameraRotation(float dx, float dy) {
    rotation.x += dx;
    rotation.y += dy;
}

void ofApp::updateCameraRotation(float dz) {
    rotation.z += dz;
}

void ofApp::updateShaders() {
    shader.load("shader.vert", "shader.frag");
}

//--------------------------------------------------------------
void ofApp::update() {
    vec3 velocityWorldSpace = mat3(rotate(-rotation.x, vec3(0, 1, 0))) * mat3(rotate(-rotation.y, vec3(1, 0, 0))) * mat3(rotate(-rotation.z, vec3(0, 0, 1))) * (velocity * 0.25);

    float dt = static_cast<float>(ofGetLastFrameTime());

    position += velocityWorldSpace * dt;
}


//--------------------------------------------------------------
void ofApp::draw(){
	float aspect = 1024.0f / 768.0f;

	mat4 model = translate(vec3(0, 0, -1)) * rotate(radians(0.0f), vec3(1, 1, 1));
	mat4 view = rotate(rotation.z, vec3(0, 0, 1)) * rotate(rotation.y, vec3(cos(-rotation.z), sin(-rotation.z), 0)) * rotate(rotation.x, vec3(sin(rotation.z), cos(rotation.z), 0)) * translate(-position);
	mat4 proj = perspective(radians(90.0f), aspect, 0.001f, 2.0f);

	mat4 mvp = proj * view * model;

	shader.begin();
	shader.setUniformTexture("tex", texture,0);
	shader.setUniformMatrix4f("mvp", mvp);
    shader.setUniform1f("scale", scale);
	shader.setUniform2f("offset", offsetSet);
	shader.setUniform1i("iter", detail);
	quad.draw();
	shader.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == 'w') {
        velocity.z = -1;
    }
    if (key == 's') {
        velocity.z = 1;
    }
    if (key == 'a') {
        velocity.x = -1;
    }
    if (key == 'd') {
        velocity.x = 1;
    }
    if (key == OF_KEY_LEFT_SHIFT) {
        velocity.y = 1;
    }
    if (key == OF_KEY_LEFT_CONTROL) {
        velocity.y = -1;
    }
    if (key == 'q') {
        detail += 10;
    }
    if (key == 'e') {
        detail -= 10;
    }

    if (key == OF_KEY_UP) {
        offsetSet.x -= scale / 5;
    }
    
    if (key == OF_KEY_DOWN) {
        offsetSet.x += scale / 5;
    }

    if (key == OF_KEY_LEFT) {
        offsetSet.y -= scale / 5;
    }
    
    if (key == OF_KEY_RIGHT) {
        offsetSet.y += scale / 5;
    }

    if (key == 'o') {
        scale *= 2;
    }
    
    if (key == 'i') {
        scale /= 2;
    }

    if (key == 'r') {
        scale = 1;
        offsetSet = glm::vec2(-0.6f, 0.5f);
    }

    if (key == OF_KEY_BACKSPACE) {
        updateShaders();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    if (key == 'w' || key == 's')
    {
        velocity.z = 0;
    }
    if (key == 'a' || key == 'd') {
        velocity.x = 0;
    }
    if (key == OF_KEY_LEFT_SHIFT || key == OF_KEY_LEFT_CONTROL) {
        velocity.y = 0;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
    //if (prevX != 0 && prevY != 0)
    //{
    //    // Update camera rotation based on mouse movement
    //    updateCameraRotation(mouseSpeed * (x - prevX), mouseSpeed * (y - prevY));
    //}

    //// Remember where the mouse was this frame.
    //prevX = x;
    //prevY = y;

    // Disabled mouse controls for easier viewing
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
