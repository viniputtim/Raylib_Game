# ifndef LOADING_HPP
# define LOADING_HPP


# include <memory>
# include "core.hpp"
# include "scenes/scene.hpp"
# include "utils/rect.hpp"
# include "utils/surf.hpp"


class Loading : public Scene
{
    private:
        std::unique_ptr<Surf> raylib;

    public:
        Loading();
        Loading(Core* core);
        ~Loading();

        void check_events() override;
        void update() override;
        void draw() override;
};


# endif