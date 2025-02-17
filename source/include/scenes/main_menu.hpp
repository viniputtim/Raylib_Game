# ifndef MAIN_MENU_HPP
# define MAIN_MENU_HPP


//# include <vector>
# include "core.hpp"
# include "scenes/scene.hpp"
# include "utils/radar_chart.hpp"


class MainMenu : public Scene
{
    private:
        RadarChart* radar_chart = new RadarChart(
            Vector2(GetScreenWidth() / 2, GetScreenHeight() / 2),
            400,
            {{"1 att", 10}, {"2 tec", 40}, {"3 sta", 50}, {"4 def", 60}, {"5 pow", 60}, {"6 vel", 45}},
            100,
            BLUE,
            BLACK
        );

    public:
        MainMenu();
        MainMenu(Core* core);
        ~MainMenu();

        void check_events() override;
        void update() override;
        void draw() override;
};


# endif