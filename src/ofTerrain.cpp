#include "ofMain.h"
#include "ofTerrain.h"

void ofTerrain::setup(){

}
ofTerrain::ofTerrain(int width, int height){
    WIDTH = width;
    HEIGHT = height;

    scale = 0.1;
    altitude = 255;
    terrain.resize(WIDTH, vector<int>(HEIGHT,0));
}


void ofTerrain::update(){

}

void ofTerrain::draw(){
    DrawCellType();
}

void ofTerrain::GenerateBaseTerrain(){
    for(int x = 0; x< this->WIDTH; x++){
        for(int y = 0; y < this -> HEIGHT; y++){
            terrain[x][y] = ofNoise(x * this -> scale, y * this -> scale) * this -> altitude;
        }
    }
}

void ofTerrain::DrawCellType(){ //This should be placed on the draw method
    for(int x = 0; x< this->WIDTH; x++){
        for(int y = 0; y < this -> HEIGHT; y++){
            float currentCell = terrain[x][y];

            if(currentCell < waterLevel){
                ofSetColor(0,0,255);
            }
            else if(currentCell < terrainLevel){
				ofSetColor(139,69,19);
			}
			else {
				ofSetColor(194,197,204);
			}

			ofDrawRectangle(x * 5, y * 5, 5, 5);
        }
    }
}

void ofTerrain::SmoothTerrain(){
    vector<vector<int>> temporalTerrain(WIDTH, vector<int>(HEIGHT, 0));
    for(int y = 1; y < this -> HEIGHT -1; y++){
        for(int x = 1; x < this -> WIDTH -1; x++){
             int sum = 0;
             int count = 0;
             
             for(int dy = -1; dy <=1; dy++){
                for(int dx = -1; dx <=1; dx++){
                    sum += terrain[x + dx][y+dy];
                    count++;
                }
             }
             int average = sum / count;
             temporalTerrain[x][y]= average;
        }
    }
    cout << "Terreno suavizado" <<endl;
    this -> terrain = temporalTerrain;
}

void ofTerrain::DrawGridInTerminal(){
    for (int y = 0; y < this->HEIGHT; y++) {
        for (int x = 0; x < this->WIDTH; x++) {

            std::cout << terrain[x][y] << " ";
        }
        std::cout << std::endl;
    }
}
//setters
void ofTerrain::setScale(float sc){
    scale = sc;
}
void ofTerrain::setAltitude(int alti){
    altitude = alti;
}
void ofTerrain::setWaterLevel(int lvl){
    waterLevel = lvl;
}
void ofTerrain::setTerrainLevel(int lvl){
    terrainLevel = lvl;
}