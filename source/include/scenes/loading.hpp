# ifndef LOADiNG_HPP
# define LOADiNG_HPP


# include "core.hpp"
# include "scenes/scene.hpp"


class Loading : public Scene
{
    public:
        Loading();
        Loading(Core* core);
        ~Loading();

        void check_events() override;
        void update() override;
        void draw() override;
};


# endif