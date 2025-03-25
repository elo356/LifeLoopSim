#pragma once
#include "ofMain.h"

class ofTerrain{

    public:
        ofTerrain(int width, int height);

        void setup();
		void update();
		void draw();

        //------------------------------------------------------
        //class methods
        void SmoothTerrain();
        void GenerateBaseTerrain();
        void DrawCellType();
        void DrawGridInTerminal();
        //--------------------------------------------------------
        //setters
        void setScale(float sc);
        void setAltitude(int alti);
        void setWaterLevel(int lv);
        void setTerrainLevel(int lvl);
        //---------------------------------------------------------

        int HEIGHT, WIDTH;
        int altitude;
        int waterLevel;
        int terrainLevel;
        float scale;

        vector<vector<int>> terrain;
};