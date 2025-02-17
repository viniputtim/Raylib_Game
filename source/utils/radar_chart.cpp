# include "utils/radar_chart.hpp"


void RadarChart::calculate_points()
{
    int i {0};

    for (auto &[label, value] : this->values)
    {
        float angle {(2 * PI / this->values.size() * i - PI / 2)};
        Vector2 point {this->polar_to_cartesian(
            this->radius * (value / this->max_value), angle
        )};
        this->points.push_back(point);

        Vector2 label_size {MeasureTextEx(
            this->font, label.c_str(), this->font_size, this->font_spacing
        )};
        Rect label_rect {label_size};
        Vector2 max_point {this->polar_to_cartesian(this->radius, angle)};
        label_rect.set_mid_bottom(max_point);
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
        DrawLineV(this->points[i], this->points[(i + 1) % this->points.size()], BLUE);
        DrawTextEx(
            this->font, label.c_str(), this->label_rects[i].get_top_left(),
            this->font_size, this->font_spacing, this->label_color
        );

        ++i;
    }
}