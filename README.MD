# Setting up Pico SDK Workspace
In order to build the project in the mcu_ws you will need to run the following commands


- `cd [PATH_TO_REPO]`
- `mkdir build`
- `cd build`
- `cmake ..; make`

There will now be a uf2 file within the build folder that can be flashed to the pico.

To flash the uf2 file to the pico you can hold down the boot button on the pico and then plug it in which will mount it like a storage device, then you copy the uf2 file onto the mounted storage device. Alternatively you can use pico-tool from the Raspberry Pi Foundation. 

You can run `cmake..; make; sudo picotool load -F [filetoflash].uf2; sudo picotool reboot` from the build folder to automatically build and copy it over, if it fails you will need to manually put it into bootsel mode as above.
