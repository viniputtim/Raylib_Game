# ifndef SCENE_HPP
# define SCENE_HPP


class Core;


# include "core.hpp"


class Scene
{
    public:
        Scene() {};
        Scene(Core* core) : core(core) {};
        virtual ~Scene() {};

        virtual void check_events() {};
        virtual void update() {};
        virtual void draw() {};

    protected:
        Core* core;
};

# endif