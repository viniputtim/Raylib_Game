# ifndef RECT_HPP
# define RECT_HPP


class Rect
{
    private:
        int width = 0;
        int height = 0;
        int left = 0;
        int top = 0;

    public:
        Rect();
        Rect(int width, int height);
        ~Rect();

        int get_width();
        int get_height();
        int get_left();
        int get_top();

        void set_width(int width);
        void set_height(int height);
        void set_left(int left);
        void set_top(int top);
};


# endif