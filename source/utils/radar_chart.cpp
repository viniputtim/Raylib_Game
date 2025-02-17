# include "utils/radar_chart.hpp"


Vector2 RadarChart::polar_to_cartesian(float radius, float angle) {
    return Vector2(this->center.x + radius * cos(angle), this->center.y + radius * sin(angle));
}


void RadarChart::calculate_points()
{
    for (int i = 0; i < this->values.size(); ++i)
    {
        float angle = (2 * PI / this->values.size()) * i - PI / 2;
        this->points.push_back(this->polar_to_cartesian(
            this->radius * (this->values[i] / this->max_value), angle
        ));
    }
}


RadarChart::RadarChart()
{

}


RadarChart::RadarChart(Vector2 center, int radius, std::vector<float> values, int max_value)
{
    this->center = center;
    this->radius = radius;
    this->values = values;
    this->max_value = max_value;

    this->calculate_points();
}


RadarChart::~RadarChart()
{

}


void RadarChart::draw()
{
    for (int i = 0; i < this->points.size(); ++i) {
        DrawLineV(this->points[i], this->points[(i + 1) % this->points.size()], BLUE);
    }
}