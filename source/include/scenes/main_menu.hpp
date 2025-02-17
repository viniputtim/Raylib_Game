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
            200,
            {{"att", 10}, {"tec", 40}, {"sta", 50}, {"def", 60}, {"pow", 60}, {"vel", 45}},
            100,
            BLUE,
            BLACK,
            GetFontDefault(),
            12
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