# NoteBuilder
#### NOTE: This project is in the early development age.
**NoteBuilder** is a tool which turns *.midi* files into minecraft
levels where you can play the music with nearly the same speed as
the original *.midi* file.  
The basic concept is to use command blocks to play a specific sound
at the specified game tick.  
A scoreboard (not displayed) will be created initially
showing the **relative** game tick. Tick 0 will be when the music
starts.  
There are two command blocks at start, one used to reset the **relative**
game tick, and the other one (**Repeat Mode**) used to increase the
**relative** game tick eventually.  
Each note in the .midi file will be equivalent to a command block in
the level. They are all **repeat command blocks** and they only play
a single sound when the **relative** game tick matches the tick when
the the note should be played at.  
After the end of the song, the **relative** game tick will be reset
to 0 and will stop increasing until the player presses the *start
button*.
## Build
### Requirement  
You need the following dependencies installed for this to be
compiled successfully:  
+ boost regex
+ zlib
+ cmake
### Installation
```shell script
cd NoteBuilder #the location of the clone of this repo
cmake install
```
## Dependencies
+ [libanvil](https://github.com/majestic53/libanvil)  
This is used to read and write region files in minecraft.  
It has been modified to fit CMake(originally using make).