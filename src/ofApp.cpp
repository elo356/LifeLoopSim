#include "ofApp.h"
//--------------------------------------------------------------

int altura = 0;
float scale=0;
void ofApp::setup(){
	gui.setup();

	gui.add(alturaSlider.setup("Alutura",255.0,0.0,255.0));
	gui.add(scaleSlider.setup("Escala",0.1,0.0,0.3));	
	gui.add(waterSlider.setup("Nivel agua",80,0,140));	
	gui.add(terrainSlider.setup("Nivel tierra",160,0,255));	

	this -> terr = new ofTerrain(200,200);
}

//--------------------------------------------------------------
void ofApp::update(){

	terr->setScale(scaleSlider);
	terr->setAltitude(alturaSlider); 
	terr->setWaterLevel(waterSlider);
	terr -> setTerrainLevel(terrainSlider);
	terr->GenerateBaseTerrain();
	//terr -> SmoothTerrain();
}

//--------------------------------------------------------------
void ofApp::draw(){
	terr->DrawCellType();
	gui.draw(); // Dibuja el panel con el slider
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//UNUSED
//--------------------------------------------------------------
void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y ){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){ }
