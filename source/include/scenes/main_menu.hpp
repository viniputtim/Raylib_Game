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
            {50, 50, 50, 50, 50, 50},
            100
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