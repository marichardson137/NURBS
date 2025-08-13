#include "raylib.h"

int main() {
    // Initialize window
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Parametric Modeling");

    SetTargetFPS(60); // Set the target frames-per-second

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Hello, raylib!", 190, 200, 20, BLACK);
        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}
