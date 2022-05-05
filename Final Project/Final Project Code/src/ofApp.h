#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
		ofShader shader;
		ofImage texture;
		ofMesh quad;
		ofCamera cam;

		void updateCameraRotation(float dx, float dy);
		void updateCameraRotation(float dz);
		void updateShaders();
		int prevX = 0, prevY = 0;

		float mouseSpeed = 0.01f;
		int detail = 100;
		glm::vec3 velocity;
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec2 offsetSet = glm::vec2(-0.6f, 0.5f);
		float scale = 1.0;

};
