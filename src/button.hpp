#pragma once
#include <raylib.h>
class Button
{
public:
    Button(const char *imagepath, Vector2 imgeposition, float scale);
    ~Button();
    void Draw();
    bool IsPressed(Vector2 mousepos,bool mousepressed);

private:
    Texture2D texture;
    Vector2 position;
};