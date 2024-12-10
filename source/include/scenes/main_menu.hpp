# ifndef MAIN_MENU_HPP
# define MAIN_MENU_HPP


# include "core.hpp"
# include "scenes/scene.hpp"


class MainMenu : public Scene
{
    public:
        MainMenu();
        MainMenu(Core* core);
        ~MainMenu();

        void check_events() override;
        void update() override;
        void draw() override;
};


# endif