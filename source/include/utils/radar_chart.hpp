# ifndef RADAR_CHART
# define RADAR_CHART


# include <raylib.h>
# include <math.h>
# include <string>
# include <utility>
# include <vector>
# include "utils/rect.hpp"


class RadarChart
{
    private:
        Vector2 center {0.0f, 0.0f};
        int radius {0};
        std::vector<std::pair<std::string, float>> values;
        float max_value {0.0f};
        Color line_color {WHITE};
        Color label_color {WHITE};
        Font font {GetFontDefault()};
        int font_size {32};
        int font_spacing {2};
        std::vector<Vector2> points;
        std::vector<Rect> label_rects;

        Vector2 polar_to_cartesian(float radius, float angle);
        void calculate_points();

    public:
        RadarChart() {};
        RadarChart(
            Vector2 center, int radius, std::vector<std::pair<std::string, float>> values, float max_value,
            Color line_color, Color label_color, Font font, int font_size
        ) :
            center(center),
            radius(radius),
            values(values),
            max_value(max_value),
            line_color(line_color),
            label_color(label_color),
            font(font),
            font_size(font_size)
        {
            this->calculate_points();
        };

        void draw();
};


# endif