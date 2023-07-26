#include "Cube.h"



double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}


Cube::Cube(Camera camera, int cameraMode) {
    this->camera = camera;
    this->cameraMode = cameraMode;
    angle = 0.0f;
    width = 1.0f;
    widthOffset = 0.5f;
    length = 1.0f;
    lengthOffset = 0.5f;
    row = 10;
    column = 10;
}
Cube::~Cube() {

}

void Cube::drawCubes() {


    for (int i = 0; i < column; i++) {

        //z coordinate of each box
        float columnOffset = (i * (width + widthOffset));

        for (int j = 0; j < row; j++) {

            //x coordinate of each box
            float rowOffset = (j * (width + widthOffset));

            //create offset based off the distance to the center
            float centerDistance = distance(columnOffset, rowOffset, 0, 0);
            float angleOffset = angle + centerDistance * .075;
            float height = sin(angleOffset) * 10;

            DrawCube({ rowOffset, 0.0f, columnOffset }, width, height, length, DARKBLUE);
            DrawCubeWires({ rowOffset, 0.0f, columnOffset }, width, height, length, GREEN);
        }
    }

    angle += 0.025f;

}
void Cube::draw() {
    

    BeginDrawing();
    ClearBackground(DARKPURPLE);
    BeginMode3D(camera);

    drawCubes();

    EndMode3D();
    EndDrawing();
    UpdateCamera(&camera, cameraMode);
}
void Cube::run() {

    while (!WindowShouldClose())
    {
        draw();
    }
    CloseWindow();
}