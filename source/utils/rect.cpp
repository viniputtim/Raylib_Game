//    I N C L U D E S


# include "utils/rect.hpp"


//    G E T    I N T S


float Rect::get_width() const
{
    return this->width;
}


float Rect::get_height() const
{
    return this->height;
}


float Rect::get_left() const
{
    return this->left;
}


float Rect::get_top() const
{
    return this->top;
}


float Rect::get_center_x() const
{
    return this->left + this->width / 2;
}


float Rect::get_center_y() const
{
    return this->top + this->height / 2;
}


float Rect::get_right() const
{
    return this->left + this->width;
}


float Rect::get_bottom() const
{
    return this->top + this->height;
}


//    G E T    V E C T O R S


Vector2 Rect::get_size() const
{
    return Vector2(
        this->width,
        this->height
    );
}


Vector2 Rect::get_top_left() const
{
    return Vector2(
        this->left,
        this->top
    );
}


Vector2 Rect::get_mid_top() const
{
    return Vector2(
        this->get_center_x(),
        this->top
    );
}


Vector2 Rect::get_top_right() const
{
    return Vector2(
        this->get_right(),
        this->top
    );
}


Vector2 Rect::get_mid_left() const
{
    return Vector2(
        this->left,
        this->get_center_y()
    );
}


Vector2 Rect::get_center() const
{
    return Vector2(
        this->get_center_x(),
        this->get_center_y()
    );
}


Vector2 Rect::get_mid_right() const
{
    return Vector2(
        this->get_right(),
        this->get_center_y()
    );
}


Vector2 Rect::get_bottom_left() const
{
    return Vector2(
        this->left,
        this->get_bottom()
    );
}


Vector2 Rect::get_mid_bottom() const
{
    return Vector2(
        this->get_center_x(),
        this->get_bottom()
    );
}


Vector2 Rect::get_bottom_right() const
{
    return Vector2(
        this->get_right(),
        this->get_bottom()
    );
}


//    G E T    R E C T A N G L E


Rectangle Rect::get_rectangle() const
{
    return Rectangle
    (
        this->left,
        this->top,
        this->width,
        this->height
    );
}


//    S E T    I N T S


void Rect::set_width(float width)
{
    this->width = (width >= 0) ? width : 0;
}


void Rect::set_height(float height)
{
    this->height = (height >= 0) ? height : 0;
}


void Rect::set_left(float left)
{
    this->left = left;
}


void Rect::set_top(float top)
{
    this->top = top;
}


void Rect::set_center_x(float center_x)
{
    this->left = center_x - this->width / 2;
}


void Rect::set_center_y(float center_y)
{
    this->top = center_y - this->height / 2;
}


void Rect::set_right(float right)
{
    this->left = right - this->width;
}


void Rect::set_bottom(float bottom)
{
    this->top = bottom - this->height;
}


//    S E T    V E C T O R S


void Rect::set_size(Vector2 size)
{
    this->set_width(size.x);
    this->set_height(size.y);
}


void Rect::set_top_left(Vector2 top_left)
{
    this->left = top_left.x;
    this->top = top_left.y;
}


void Rect::set_mid_top(Vector2 mid_top)
{
    this->set_center_x(mid_top.x);
    this->top = mid_top.y;
}


void Rect::set_top_right(Vector2 top_right)
{
    this->set_right(top_right.x);
    this->top = top_right.y;
}


void Rect::set_mid_left(Vector2 mid_left)
{
    this->left = mid_left.x;
    this->set_center_y(mid_left.y);
}


void Rect::set_center(Vector2 center)
{
    this->set_center_x(center.x);
    this->set_center_y(center.y);
}


void Rect::set_mid_right(Vector2 mid_right)
{
    this->set_right(mid_right.x);
    this->set_center_y(mid_right.y);
}


void Rect::set_bottom_left(Vector2 bottom_left)
{
    this->left = bottom_left.x;
    this->set_bottom(bottom_left.y);
}


void Rect::set_mid_bottom(Vector2 mid_bottom)
{
    this->set_center_x(mid_bottom.x);
    this->set_bottom(mid_bottom.y);
}


void Rect::set_bottom_right(Vector2 bottom_right)
{
    this->set_right(bottom_right.x);
    this->set_bottom(bottom_right.y);
}


//    S E T    R E C T A N G L E


void Rect::set_rectangle(Rectangle rect)
{
    this->width = rect.width;
    this->height = rect.height;
    this->left = rect.x;
    this->top = rect.y;
}


// M O V E M E N T


void Rect::move_x(float dx)
{
    this->left += dx;
}


void Rect::move_y(float dy)
{
    this->top += dy;
}


void Rect::move(Vector2 d)
{
    this->left += d.x;
    this->top += d.y;
}