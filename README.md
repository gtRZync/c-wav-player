>[!IMPORTANT]
>Development paused due to school. Planned improvements:  
>- Refactor code structure for clarity and maintainability  
>- Make playback thread-safe for asynchronous audio handling  

# c-wav-player: Custom WAV File Parser & Win32 Audio Player in C

**c-wav-player** is a lightweight, low-level WAV file parser and Windows audio player written in C. It reads standard RIFF/WAV headers, skips unknown metadata chunks (like `smpl`, `LIST`, etc.), extracts raw PCM audio data, and plays it via the Windows `waveOut*` API — all without relying on the high-level, limited `PlaySound` function.


## Features

* **WAV Parsing**

  * Reads and validates standard RIFF/WAV headers
  * Supports 16-bit PCM, stereo and mono audio
  * Safely skips unknown chunks for robust parsing
  * Prints header info (channels, sample rate, bit depth, duration)

* **Audio Playback**

  * Non-blocking playback using a clean `Sound*` interface
  * Integrates with a UI/game loop
  * Handles real-time streaming of PCM data

* **Why Not `PlaySound`?**

  * `PlaySound` is **blocking**, limited, and can’t stream large or custom WAV files efficiently
  * `waveOut*` allows **asynchronous playback, low-level control, and robust error handling**

* **Platform Notes**

  * **WAV parser** is cross-platform and can be reused on any OS
  * **Sound player (`waveOut*`) is Win32-only**, so playback is Windows-specific

## Usage Example 

### Wav Parser

```c
#include "wav_parser.h"

int main(int argc, char const *argv[])
{
    wav_file_t file;
    wav_init_file(&file);

    if(!wav_parse_file("resources/sound/FlappyBird_Menu.wav", &file)) {
        return 1; //better err code comming soon
    }

    // Example: Access audio data via file.data / file.samples

    wav_free_file(&file);
    return 0;
}
```

### Win32 Soundplayer(using the wav parser)
```c
#include "win32/soundplayer.h"

int main(int argc, char const *argv[])
{
    Sound* snd = sound_init("resources/sound/bass-wiggle.wav");
    play_sound(snd);

    while(sound_is_playing(snd)) {
        draw_ui();
    }

    sound_release(snd);
    return 0;
}
```

## WAV parser (header data display)

|          WAV header data                              |
|-------------------------------------------------------|
| ![Demo](resources/images/demo.png)                    |

## License

This project is open source and free to use under the [MIT License](LICENSE).

