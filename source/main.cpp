# include <raylib.h>
# include "core.hpp"


int main(int argc, const char * argv[])
{
    InitWindow(0, 0, "Meu Jogo");
    ToggleFullscreen();
    InitAudioDevice();
    SetMasterVolume(0.5);
    Core core;
    core.run();
    CloseWindow();
    CloseAudioDevice();
    return 0;
}