# ifndef LOADING_HPP
# define LOADING_HPP


# include <memory>
# include <vector>
# include <raylib.h>
# include "core.hpp"
# include "scenes/scene.hpp"
# include "utils/rect.hpp"
# include "utils/surf.hpp"


class Loading : public Scene
{
    private:
        std::unique_ptr<Surf> raylib;
        Vector2 logo_movement {1, 1};
        int logo_speed {400};
        std::vector<Color> colors {RED, GREEN, BLUE};
        unsigned short int color {0};

    public:
        Loading();
        Loading(Core* core);
        ~Loading();

        void check_events() override;
        void update() override;
        void draw() override;
};


# endif