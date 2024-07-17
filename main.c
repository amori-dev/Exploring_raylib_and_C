#include "raylib.h"
#include "raymath.h"

struct Window {
    int width;
    int height;
    Color bgColor;
};

struct Player {
    float speed;
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
    player.texture = (Texture2D)LoadTexture("Art/player.png");
    player.pos = (Vector2){0, 0};
    player.vel = (Vector2){0, 0};

    cam.target = player.pos;
    cam.offset = (Vector2){window.width / 2, window.height / 2};
    cam.zoom = 1.0;

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_A)) { 
            player.vel.x = -1;
        }
        else if (IsKeyDown(KEY_D)) {
            player.vel.x = 1;
        }
        else {
            player.vel.x = 0;
        }

        if (IsKeyDown(KEY_W)) {
            player.vel.y = -1;
        }
        else if (IsKeyDown(KEY_S)) {
            player.vel.y = 1;
        }
        else {
            player.vel.y = 0;
        }

        if (Vector2Length(player.vel) != 0) {
            player.vel = Vector2Normalize(player.vel);
            player.vel = Vector2Scale(player.vel, player.speed * GetFrameTime());
        }

        player.pos = Vector2Add(player.pos, player.vel);

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
