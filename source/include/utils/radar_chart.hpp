# ifndef RADAR_CHART
# define RADAR_CHART


# include <raylib.h>
# include <math.h>
# include <vector>


class RadarChart
{
    private:
        Vector2 center;
        int radius;
        std::vector<float> values;
        int max_value;
        std::vector<Vector2> points;

        Vector2 polar_to_cartesian(float radius, float angle);
        void calculate_points();

    public:
        RadarChart();
        RadarChart(Vector2 center, int radius, std::vector<float> values, int max_value);
        ~RadarChart();

        void draw();
};


# endif