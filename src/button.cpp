#include "button.hpp"

Button::Button(const char *imagepath, Vector2 imgeposition, float scale)
{
    Image image = LoadImage(imagepath);
    int OriginalHeight = image.height;
    int OriginalWidth = image.width;

    int NewHeigth = static_cast<int>(OriginalHeight * scale);
    int NewWidth = static_cast<int>(OriginalWidth * scale);

    ImageResize(&image, NewWidth, NewHeigth);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    position = imgeposition;
}
Button::~Button()
{
    UnloadTexture(texture);
}
void Button::Draw()
{
    DrawTextureV(texture, position, WHITE);
}

bool Button::IsPressed(Vector2 mousepos, bool mousepressed)
{
    Rectangle rect = {position.x, position.y, static_cast<float>(texture.width), static_cast<float>(texture.height)};
    if (CheckCollisionPointRec(mousepos, rect) && mousepressed)
    {
        return true;
    }
    
    return false;
}
