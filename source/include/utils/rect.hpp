# ifndef RECT_HPP
# define RECT_HPP


# include <raylib.h>


class Rect
{
    private:
        float width {0};
        float height {0};
        float left {0};
        float top {0};

    public:
        Rect();
        Rect(Vector2 size) : width(size.x), height(size.y) {};
        Rect(Rectangle rect) : left(rect.x), top(rect.y), width(rect.width), height(rect.height) {};

        float get_width() const;
        float get_height() const;
        float get_left() const;
        float get_top() const;
        float get_center_x() const;
        float get_center_y() const;
        float get_right() const;
        float get_bottom() const;

        Vector2 get_size() const;
        Vector2 get_top_left() const;
        Vector2 get_mid_top() const;
        Vector2 get_top_right() const;
        Vector2 get_mid_left() const;
        Vector2 get_center() const;
        Vector2 get_mid_right() const;
        Vector2 get_bottom_left() const;
        Vector2 get_mid_bottom() const;
        Vector2 get_bottom_right() const;

        Rectangle get_rectangle() const;

        void set_width(float width);
        void set_height(float height);
        void set_left(float left);
        void set_top(float top);
        void set_center_x(float center_x);
        void set_center_y(float center_y);
        void set_right(float right);
        void set_bottom(float bottom);

        void set_size(Vector2 size);
        void set_top_left(Vector2 top_left);
        void set_mid_top(Vector2 mid_top);
        void set_top_right(Vector2 top_right);
        void set_mid_left(Vector2 mid_left);
        void set_center(Vector2 center);
        void set_mid_right(Vector2 mid_right);
        void set_bottom_left(Vector2 bottom_left);
        void set_mid_bottom(Vector2 mid_bottom);
        void set_bottom_right(Vector2 bottom_right);

        void set_rectangle(Rectangle rect);

        void move_x(float dx);
        void move_y(float dy);
        void move(Vector2 d);
};


# endif