# ifndef RADAR_CHART
# define RADAR_CHART


# include <raylib.h>
# include <math.h>
# include <map>
# include <string>
# include <vector>
# include "utils/rect.hpp"


class RadarChart
{
    private:
        Vector2 center;
        int radius;
        std::map<std::string, float> values;
        int max_value;
        std::vector<Vector2> points;
        std::vector<Rect> label_rects;
        Color line_color;
        Color label_color;
        int font_spacing = 2;
        Font font = GetFontDefault();
        int font_size = 32;

        Vector2 polar_to_cartesian(float radius, float angle);
        void calculate_points();

    public:
        RadarChart();
        RadarChart(
            Vector2 center, int radius, std::map<std::string, float> values, int max_value,
            Color line_color, Color label_color
        );
        ~RadarChart();

        void draw();
};


# endif