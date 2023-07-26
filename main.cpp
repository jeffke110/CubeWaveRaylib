/*******************************************************************************************
*
*   Cube Wave - Jeffrey Kedda
*
*   Made a simple cube wave using the sine function, distance formula, and offsets
*
********************************************************************************************/

#include "Cube.h"


void setUpCamera(Camera& camera) {
    camera.position = Vector3{ 32.0f, 16.0f, 32.0f };    // Camera position
    camera.target = Vector3{ 7.5f, 2.0f, 7.5f };      // Camera looking at point
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type
}


void windowInit() {
    const int screenWidth = 1024;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Cube Wave - Jeffrey Kedda");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetWindowMinSize(screenWidth, screenHeight);
    SetTargetFPS(60);
}

int main(void)
{

    windowInit();
    Camera camera = { 0 };
    int cameraMode = CAMERA_ORBITAL;
    setUpCamera(camera);
    Cube cube = Cube(camera, cameraMode);
    cube.run();

    
    return 0;
}