#include <iostream>
using namespace std;
#include "raylib.h"
#include "button.hpp"

int main()
{
    const int windowX = 1280;
    const int windowY = 720;
    InitWindow(windowX, windowY, "CPP GAME :)");
    SetTargetFPS(60);

    Texture2D background = LoadTexture("./Graphics/bg (Custom).jpg");

    // Button size scaling
    float snakeScale = 0.7;
    float spaceScale = 0.7;
    float exitScale = 0.5;

    // Calculate button widths after scaling
    Texture2D snakeTexture = LoadTexture("./graphics/SnakeGame.jpg");
    // Texture2D spaceTexture = LoadTexture("./graphics/SpaceWar (custom).jpg");
    // Texture2D exitTexture = LoadTexture("./graphics/exit (Custom).png");

    float buttonWidth = snakeTexture.width * snakeScale;
    float centerX = (windowX - buttonWidth) / 2;

    // Properly spaced buttons
    Button SnakeStartButton{"./graphics/SnakeGame.jpg", {centerX, 280}, snakeScale};
    Button SpaceWarStartButton{"./graphics/SpaceWar (custom).jpg", {centerX, 400}, spaceScale};
    Button exitButton{"./graphics/exit (custom).png", {centerX - 47, 460}, exitScale}; // Slight offset for emphasis

    // const int windowX = 1280;
    // const int windowY = 720;

    // InitWindow(windowX, windowY, "Game Button Test");
    // SetTargetFPS(165);
    // Texture2D background = LoadTexture("./Graphics/background.jpg");
    // Button SnakeStartButton{"./graphics/SnakeGame.jpg", {60, 250}, 0.7};
    // Button SpaceWarStartButton{"./graphics/SpaceWar (custom).jpg", {80, 340}, 0.7};
    // Button exitButton{"./graphics/exit.png", {150, 400}, 0.35};
    bool exit = false;

    while (!WindowShouldClose() && !exit)
    {
        Vector2 MousePosition = GetMousePosition();
        bool mousepressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if (SnakeStartButton.IsPressed(MousePosition, mousepressed))
        {
            cout << "Starting Snake Game..." << endl;
            system("SnakeGame.exe");
        }
        if (SpaceWarStartButton.IsPressed(MousePosition, mousepressed))
        {
            cout << "Starting SpaceWar Game..." << endl;
            system("SpaceWar.exe");
        }

        if (exitButton.IsPressed(MousePosition, mousepressed))
        {
            cout << "EXITING.............." << endl;
            exit = true;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background, 0, 0, WHITE);

        // Centered text
        const char *titleText = "Welcome to the Game Hub";
        int fontSize = 60;
        int textWidth = MeasureText(titleText, fontSize);
        DrawText(titleText, (windowX - textWidth) / 2, 50, fontSize, BLACK);

        SnakeStartButton.Draw();
        SpaceWarStartButton.Draw();
        exitButton.Draw();
        EndDrawing();
    }

    CloseWindow();
}
