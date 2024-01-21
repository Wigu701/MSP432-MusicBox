# MSP432-MusicBox
This is a multi-track music player project designed to run on the MSP432 microcontroller. The code is organized into tasks run concurrently by FreeRTOS. 

## Known Issues
For longer songs in duet mode (concurrent playing with 2 microcontrollers), desync begins to accumulate. Solving this will likely require an overhaul of the duet signaling to sync time steps at a fixed frequency.
