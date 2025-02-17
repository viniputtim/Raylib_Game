# ifndef SURF_HPP
# define SURF_HPP


# include <raylib.h>
# include <memory>
# include <string>
# include "utils/rect.hpp"


class Surf
{
    private:
        Image image;
        Texture2D texture;
        std::shared_ptr<Rect> rect;
        Color color {WHITE};
    public:
        Surf();
        Surf(std::string file_path, Color color);
        ~Surf();

        std::shared_ptr<Rect> get_rect();
        Color get_color();
        void set_color(Color color);
        void draw();
};

# endif