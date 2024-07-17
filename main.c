#include "raylib.h"
#include "raymath.h"

struct Window {
    int width;
    int height;
    Color bgColor;
};

struct Player {
    float speed;
    float friction;
    float gravity;
    Vector2 pos;
    Vector2 vel;
    Texture2D texture;
};

struct Player player;
struct Window window;
struct Camera2D cam;

int main(void) {
    window.width = 1280;
    window.height = 720;
    window.bgColor = (Color){229, 74, 74, 225};

    InitWindow(window.width, window.height, "");

    player.speed = 400.0;
    player.friction = 0.01;
    player.gravity = 0;
    player.texture = (Texture2D)LoadTexture("Art/player.png");
    player.pos = (Vector2){0, 0};
    player.vel = (Vector2){0, 0};

    cam.target = player.pos;
    cam.offset = (Vector2){window.width / 2, window.height / 2};
    cam.zoom = 1.0;

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        if (IsKeyDown(KEY_A)) {
            player.vel.x = -player.speed * dt;
        }
        else if (IsKeyDown(KEY_D)) {
            player.vel.x = player.speed * dt;
        }
        else {
            // decel to a stop
        }

        BeginDrawing();
        BeginMode2D(cam);
        ClearBackground(window.bgColor);

        DrawTextureEx(player.texture, player.pos, 0, 0.7, WHITE);
        EndMode2D();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
