#include "raylib.h"
#include <math.h>

// small project to train and use the concepts from the raylib documentation 
// additional to my tiny_circle_simulation (Circle Wikipedia for cos/sin explanation)
// uses the raylib cheatsheet page for creating the shapes. Fpr  

#define WIDTH 900
#define HEIGHT 600
#define NUM_ORBITS_CIRCLES 6 

int main(void) {
    InitWindow(WIDTH, HEIGHT, "3D Shapes first attempt");

    Camera camera = {0};
    camera.position = (Vector3) {0.0f, 10.0f, 10.0f};
    camera.target = (Vector3) {0.0f, 0.0f, 0.0f};
    camera.up = (Vector3) {0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    
    DisableCursor();
    SetTargetFPS(60);
    DrawFPS(10, 10);
    
    while (!WindowShouldClose()) {
    
    float t = (float)GetTime();
    UpdateCamera(&camera, CAMERA_FREE);
    BeginDrawing();
    ClearBackground(BLACK);
    BeginMode3D(camera);

    for (int i = 0; i < NUM_ORBITS_CIRCLES; i++) {
        float angle = t + (6.0f / NUM_ORBITS_CIRCLES) * i;
        float radius = 5.0f;
        Vector3 pos = {
            cosf(angle) * radius,
            sinf(t * 0.7f + i) * 1.2f,
            sinf(angle) * radius
        };
        DrawSphere(pos, 0.45f, ColorFromHSV(fmod(t * 40.0f, 360.0f), 0.9f, 1.0f));
        DrawSphereWires(pos, 0.48f, 6, 6, WHITE);
    }

    float pulse = 0.3f * sinf(t * 2.0f);
    Vector3 cube_pos = {0.0f, pulse, 0.0f};
    DrawCube(cube_pos, 2.0f, 2.0f, 2.0f, ColorFromHSV(fmod(t *40.0f, 360.0f), 0.9f, 1.0f));
    

    DrawCube( (Vector3) {-4.0f, 0.0f, 2.0f}, 2.0f, 2.0f, 2.0f, RED);
    DrawCubeWires( (Vector3) {-4.0f, 0.0f, 2.0f}, 2.0f, 2.0f, 2.0f, ORANGE);
    DrawCubeWires((Vector3) {4.0, 1.05f, -2.0f}, 2.0f, 2.0f, 2.0f, MAGENTA);
    DrawCapsuleWires((Vector3) {-3.0f, 1.5f, -4.0f}, (Vector3) {-4.0f, -1.0f, -4.0f}, 1.2f, 8, 8, PURPLE);
    DrawTriangle3D((Vector3) {2.0f, 0.0f, -4.0f}, (Vector3) {4.0, 2.5f, -4.0f}, (Vector3) {0.0f, 2.5f, -4.0f}, MAROON);
    DrawSphereWires((Vector3) {1.0f, 2.0f, -1.5f}, 1.2, 10, 8, SKYBLUE);
    DrawCylinder ( ( Vector3 ) { 4.0f, 0.0f, 2.0f }, 1.0f, 2.0f, 3.0f, 4, SKYBLUE );
    DrawCylinderWires ( ( Vector3 ) { 4.0f, 0.0f, 2.0f }, 1.0f, 2.0f, 3.0f, 4, DARKBLUE );
    DrawSphereWires ( ( Vector3 ) { 0.0f, 0.0f, 2.0f }, 2.0f, 16, 16, LIME );

    DrawGrid(10, 1.0f);
    EndMode3D();
    DrawText("<WASD> for moving  |  Mouse for viewing", 4.0f , 580.0f, 17.0f, RAYWHITE);
    EndDrawing();
    }
    
    EnableCursor();
    CloseWindow();
    return 0;
}
