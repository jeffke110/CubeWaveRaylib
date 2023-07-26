#pragma once
#ifndef CUBE_H
#define CUBE_H

#include "raylib.h"
#include "rcamera.h"

#include <cmath>
#include <iostream>

class Cube {

public:
	Cube(Camera camera, int cameraMode);
	~Cube();
	void draw();
	void drawCubes();
	void run();

private:
	float width;
	float widthOffset;
	float length;
	float lengthOffset;

	int row;
	int column;

	Camera camera;
	int cameraMode;
	float angle;

};




#endif // !CUBE_H
