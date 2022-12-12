#include "raylib.h"

int main(void){
    InitWindow(640, 480, "GAME");
    SetTargetFPS(60);

    while (!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("i think the default font is really cool", 130, 220, 20, LIGHTGRAY);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
