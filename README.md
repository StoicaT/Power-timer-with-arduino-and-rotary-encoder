instead of the classic relay

# Power-timer-with-arduino-and-rotary-encoder

Hardware, the timer consists of the one described at:

https://github.com/StoicaT/Timer-with-Arduino-and-rotary-encoder-1

to which is added the power supply and instead of the classic relay
a power actuating element.
Everything is encased in a metal box.

Software can be the one from the previous address, or from the address:

https://github.com/StoicaT/Timer-with-Arduino-and-rotary-encoder-2

or the one in this repository.

In the first two cases, we have a countdown counter.Its programming is described at the appropriate addresses.

In the last case we have a timer whose duration and ON / OFF cycles are preset.
There are 3 predefined programs that operate an electric motor that can operate a mixer (for dough for example).
Its programming is simple:

-Choose one of the 3 programs by rotating the Encoder.
-Start the program by pressing the Rotary Encoder button.

The program given in this repository can be easily modified for other applications, because the number of ON / OFF cycles can be easily modified, as well as their duration.
