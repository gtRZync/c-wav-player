#include "soundplayer.h"
#include "playsound_tui_demo.h"

int main(int argc, char const *argv[])
{
    const char* filepath = "resources/sound/bass-wiggle.wav";
    Sound *snd = sound_init(filepath);

    play_sound(snd);
    playsound_ui_demo(snd);

    //?for replay demo purposes
    play_sound(snd);
    playsound_tui_demo(snd, filepath);

    sound_release(snd);
    return 0;
}