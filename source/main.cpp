# include "core.hpp"


int main()
{
    InitAudioDevice();
    SetMasterVolume(0.5);
    InitWindow(0, 0, "CLICK AND COMMAND");
    ToggleFullscreen();
    Core core;
    core.run();
    CloseAudioDevice();
    CloseWindow();


    return 0;
}