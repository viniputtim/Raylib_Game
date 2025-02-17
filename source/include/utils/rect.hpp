# ifndef RECT_HPP
# define RECT_HPP


# include <raylib.h>


class Rect
{
    private:
        int width {0};
        int height {0};
        int left {0};
        int top {0};

    public:
        Rect();
        Rect(Vector2 size) : width(size.x), height(size.y) {};
        Rect(Rectangle rect) : left(rect.x), top(rect.y), width(rect.width), height(rect.height) {};

        int get_width() const;
        int get_height() const;
        int get_left() const;
        int get_top() const;
        int get_center_x() const;
        int get_center_y() const;
        int get_right() const;
        int get_bottom() const;

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

        void set_width(int width);
        void set_height(int height);
        void set_left(int left);
        void set_top(int top);
        void set_center_x(int center_x);
        void set_center_y(int center_y);
        void set_right(int right);
        void set_bottom(int bottom);

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
};


# endif