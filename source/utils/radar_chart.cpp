# include "utils/radar_chart.hpp"


void RadarChart::calculate_points()
{
    int i {0};

    for (auto &[label, value] : this->values)
    {
        float angle {(2 * PI / this->values.size() * i - PI / 2)};
        this->points.push_back(this->polar_to_cartesian(
            this->radius * (value / this->max_value), angle
        ));

        Vector2 label_size {MeasureTextEx(
            this->font, label.c_str(), this->font_size, this->font_spacing
        )};
        Rect label_rect {label_size};
        label_rect.set_center(this->polar_to_cartesian(this->radius, angle));
        this->label_rects.push_back(label_rect);

        ++i;
    }
}


Vector2 RadarChart::polar_to_cartesian(float radius, float angle) {
    return Vector2(this->center.x + radius * cos(angle), this->center.y + radius * sin(angle));
}


void RadarChart::draw()
{
    int i {0};

    for (auto &[label, value] : this->values) {
        DrawTriangle(
            this->points[i], this->center, this->points[(i + 1) % this->points.size()],
            this->line_color
        );

        DrawTextEx(
            this->font, label.c_str(), this->label_rects[i].get_top_left(),
            this->font_size, this->font_spacing, this->label_color
        );

        ++i;
    }
}