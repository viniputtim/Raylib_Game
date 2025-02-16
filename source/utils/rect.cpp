# include "utils/rect.hpp"


Rect::Rect()
{

}


Rect::Rect(int width, int height)
{
    this->width = width;
    this->height = height;
}


Rect::~Rect()
{

}


int Rect::get_width()
{
    return this->width;
}


int Rect::get_height()
{
    return this->height;
}


int Rect::get_left()
{
    return this->left;
}


int Rect::get_top()
{
    return this->top;
}


void Rect::set_width(int width)
{
    this->width = width;
}


void Rect::set_height(int height)
{
    this->height = height;
}


void Rect::set_left(int left)
{
    this->left = left;
}


void Rect::set_top(int top)
{
    this->top = top;
}