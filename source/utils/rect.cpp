/*
    I N C L U D E S
*/


# include "utils/rect.hpp"


/*
    C O N S T R U T O R E S    E    D E S T R U T O R E S
*/


Rect::Rect()
{

}


Rect::Rect(int width, int height)
{
    this->width = width;
    this->height = height;
}


Rect::Rect(Rectangle rect)
{
    this->width = static_cast<int> (rect.width);
    this->height = static_cast<int> (rect.height);
    this->left = static_cast<int> (rect.x);
    this->top = static_cast<int> (rect.y);
}


Rect::~Rect()
{

}


/*
    G E T    I N T S
*/


int Rect::get_width() const
{
    return this->width;
}


int Rect::get_height() const
{
    return this->height;
}


int Rect::get_left() const
{
    return this->left;
}


int Rect::get_top() const
{
    return this->top;
}


int Rect::get_center_x() const
{
    return this->left + this->width / 2;
}


int Rect::get_center_y() const
{
    return this->top + this->height / 2;
}


int Rect::get_right() const
{
    return this->left + this->width;
}


int Rect::get_bottom() const
{
    return this->top + this->height;
}


/*
    G E T    V E C T O R S
*/


Vector2 Rect::get_size() const
{
    return Vector2(
        static_cast<float> (this->width),
        static_cast<float> (this->height)
    );
}


Vector2 Rect::get_top_left() const
{
    return Vector2(
        static_cast<float> (this->left),
        static_cast<float> (this->top)
    );
}


Vector2 Rect::get_mid_top() const
{
    return Vector2(
        static_cast<float> (this->get_center_x()),
        static_cast<float> (this->top)
    );
}


Vector2 Rect::get_top_right() const
{
    return Vector2(
        static_cast<float> (this->get_right()),
        static_cast<float> (this->top)
    );
}


Vector2 Rect::get_mid_left() const
{
    return Vector2(
        static_cast<float> (this->left),
        static_cast<float> (this->get_center_y())
    );
}


Vector2 Rect::get_center() const
{
    return Vector2(
        static_cast<float> (this->get_center_x()),
        static_cast<float> (this->get_center_y())
    );
}


Vector2 Rect::get_mid_right() const
{
    return Vector2(
        static_cast<float> (this->get_right()),
        static_cast<float> (this->get_center_y())
    );
}


Vector2 Rect::get_bottom_left() const
{
    return Vector2(
        static_cast<float> (this->left),
        static_cast<float> (this->get_bottom())
    );
}


Vector2 Rect::get_mid_bottom() const
{
    return Vector2(
        static_cast<float> (this->get_center_x()),
        static_cast<float> (this->get_bottom())
    );
}


Vector2 Rect::get_bottom_right() const
{
    return Vector2(
        static_cast<float> (this->get_right()),
        static_cast<float> (this->get_bottom())
    );
}

/*
    G E T    R E C T A N G L E
*/


Rectangle Rect::get_rectangle() const
{
    return Rectangle
    (
        static_cast<float> (this->left),
        static_cast<float> (this->top),
        static_cast<float> (this->width),
        static_cast<float> (this->height)
    );
}


/*
    S E T    I N T S
*/


void Rect::set_width(int width)
{
    this->width = (width >= 0) ? width : 0;
}


void Rect::set_height(int height)
{
    this->height = (height >= 0) ? height : 0;
}


void Rect::set_left(int left)
{
    this->left = left;
}


void Rect::set_top(int top)
{
    this->top = top;
}


void Rect::set_center_x(int center_x)
{
    this->left = center_x - this->width / 2;
}


void Rect::set_center_y(int center_y)
{
    this->top = center_y - this->height / 2;
}


void Rect::set_right(int right)
{
    this->left = right - this->width;
}


void Rect::set_bottom(int bottom)
{
    this->top = bottom - this->height;
}


/*
    S E T    V E C T O R S
*/


void Rect::set_size(Vector2 size)
{
    this->set_width(static_cast<int> (size.x));
    this->set_height(static_cast<int> (size.y));
}


void Rect::set_top_left(Vector2 top_left)
{
    this->left = static_cast<int> (top_left.x);
    this->top = static_cast<int> (top_left.y);
}


void Rect::set_mid_top(Vector2 mid_top)
{
    this->set_center_x(static_cast<int> (mid_top.x));
    this->top = static_cast<int> (mid_top.y);
}


void Rect::set_top_right(Vector2 top_right)
{
    this->set_right(static_cast<int> (top_right.x));
    this->top = static_cast<int> (top_right.y);
}


void Rect::set_mid_left(Vector2 mid_left)
{
    this->left = static_cast<int> (mid_left.x);
    this->set_center_y(static_cast<int> (mid_left.y));
}


void Rect::set_center(Vector2 center)
{
    this->set_center_x(static_cast<int> (center.x));
    this->set_center_y(static_cast<int> (center.y));
}


void Rect::set_mid_right(Vector2 mid_right)
{
    this->set_right(static_cast<int> (mid_right.x));
    this->set_center_y(static_cast<int> (mid_right.y));
}


void Rect::set_bottom_left(Vector2 bottom_left)
{
    this->left = static_cast<int> (bottom_left.x);
    this->set_bottom(static_cast<int> (bottom_left.y));
}


void Rect::set_mid_bottom(Vector2 mid_bottom)
{
    this->set_center_x(static_cast<int> (mid_bottom.x));
    this->set_bottom(static_cast<int> (mid_bottom.y));
}


void Rect::set_bottom_right(Vector2 bottom_right)
{
    this->set_right(static_cast<int> (bottom_right.x));
    this->set_bottom(static_cast<int> (bottom_right.y));
}


/*
    S E T    R E C T A N G L E
*/

void Rect::set_rectangle(Rectangle rect)
{
    this->width = static_cast<int> (rect.width);
    this->height = static_cast<int> (rect.height);
    this->left = static_cast<int> (rect.x);
    this->top = static_cast<int> (rect.y);
}