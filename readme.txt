Program runs if compiled on a C++ compiler.
Program runs all traffic lights at intersection through 4 complete cycles.

Assuming you have compiled the program source code (traffic.cpp) on a Windows-based PC, open a command 
prompt window and navigate to the directory containing "traffic.exe" and enter:

traffic.exe >results.txt

After pressing the <Enter> key the program will run and create a text file called results.txt that will
contain the program output. 

Use Notepad to view the contents of 'results.txt'.

The format of 'results.txt' is explained below.

Each row of output contains 9 fields: Time, NBLT, SBLT, NBTH, SBTH, EBLT, WBLT, EBTH, and WBTH.
The Time field represents the number of seconds since the current traffic light cycle began.
The NBLT field represents the color of the northbound left turn light.
The SBLT field represents the color of the southbound left turn light.
The NBTH field represents the color of the northbound through lane light.
the SBTH field represents the color of the southbound through lane light.
The EBLT field represents the color of the eastbound left turn light.
the WBLT field represents the color of the westbound left turn light.
the EBTH field represents the color of the eastbound through lane light.
the WBTH field represents the color of the westbound through lane light.
Colors are represented by integers in the range of 0 - 2.
Green is represented by 0. Yellow is represented by 1. Red is represented by 2. Provisions have been 
made to represent orange by 3, but orange isn't used in the current version.

