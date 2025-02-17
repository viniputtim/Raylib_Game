# include "utils/radar_chart.hpp"


Vector2 RadarChart::polar_to_cartesian(float radius, float angle) {
    return Vector2(this->center.x + radius * cos(angle), this->center.y + radius * sin(angle));
}


void RadarChart::calculate_points()
{
    int size = this->values.size();
    int i = 0;

    for (auto it = this->values.begin(); it != this->values.end(); ++it)
    {
        float angle = (2 * PI / size * i - PI / 2);
        Vector2 point = this->polar_to_cartesian(
            this->radius * (it->second / this->max_value), angle
        );
        this->points.push_back(point);

        Vector2 label_size = MeasureTextEx(
            this->font, it->first.c_str(), this->font_size, this->font_spacing
        );
        Rect label_rect {label_size.x, label_size.y};
        label_rect.set_mid_bottom(point);
        this->label_rects.push_back(label_rect);

        ++i;
    }
}


RadarChart::RadarChart()
{

}


RadarChart::RadarChart(
    Vector2 center, int radius, std::map<std::string, float> values, int max_value,
    Color line_color, Color label_color
)
{
    this->center = center;
    this->radius = radius;
    this->values = values;
    this->max_value = max_value;
    this->line_color = line_color;
    this->label_color = label_color;

    this->calculate_points();
}


RadarChart::~RadarChart()
{

}


void RadarChart::draw()
{
    int i = 0;

    for (auto it = this->values.begin(); it != this->values.end(); ++it) {
        DrawLineV(this->points[i], this->points[(i + 1) % this->points.size()], BLUE);
        DrawTextEx(
            this->font, it->first.c_str(), this->label_rects[i].get_top_left(),
            this->font_size, this->font_spacing, this->label_color
        );

        ++i;
    }
}