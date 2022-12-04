# Beeper
Beeper is a simple command line utility that prints ascii bell characters to the terminal to alert users. Its intended usecase is to alert a user for when a long running console program has ended.

For example, the following code will beep after long command has ended:
```bash
long-command ; beeper
```
Or alternatively you can have the console beeping continously every few seconds(in this case 5):
```bash
long-command ; beeper -l 5
```

## Options
This utility supports 2 command line flags, `-h|--help` for printing the help menu and `-l|--loop <time|10>` for repeating the beep every `time` seconds (defaults to 10).

## Building
You only need a GCC compatible C compiler and GNU make to build this program, the following line will build it and install it to the /bin directory of your system under posix systems.

```bash
make;sudo make install
```
It is also possible to build this program using Microsoft Visual C++, simply open the folder in a visual studio developer command prompt and run:
```cmd
cl beeper.c /O2
```
This will create a beeper.exe in the current folder that you can simple move to a folder in `PATH` of your choosing.

I have tested this program under Windows 11 using both GCC 12.2.0 and MSVC 19.35.31935 and under Fedora Linux 37 using GCC 12.2.1, try any other platforms at your own discretion.