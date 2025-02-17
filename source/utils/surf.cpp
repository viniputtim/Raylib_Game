# include "utils/surf.hpp"


Surf::Surf()
{

}


Surf::Surf(std::string file_path, Color color)
{
    this->image = LoadImage(TextFormat("../resources/graphics/%s", file_path.c_str()));
    this->texture = LoadTextureFromImage(this->image);
    this->rect = std::make_shared<Rect> (Vector2(
        static_cast<float> (this->texture.width), static_cast<float> (this->texture.height)
    ));
    this->color = color;
}

Surf::~Surf()
{
    UnloadImage(this->image);
    UnloadTexture(this->texture);
}


std::shared_ptr<Rect> Surf::get_rect()
{
    return this->rect;
}


Color Surf::get_color()
{
    return this->color;
}


void Surf::set_color(Color color)
{
    this->color = color;
}


void Surf::draw()
{
    DrawTexture(this->texture, this->rect->get_left(), this->rect->get_top(), this->color);
}