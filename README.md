### Working with ESP8266 on mac (Sierra) with C/C++

##### Chips: WEMOSE D1 Mini v2.2.0

NetBean as a IDE

`Sming-docker` container as remote build host



##### Steps

1. Install driver: https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver
   1. To check if driver and the device work correctly as the first step of development: the serial should appear under `/dev`, such as `/dev/tty.wchusbserial14510`

2. Pull `sming-docker` container (Github repo)[https://github.com/fernandopasse/sming-docker].
   1. As current Mac docker is now using docker-engine instead of `kitematic`, so you don't need to follow the instruction of the repo. 
   2. Run the container using command like 
    ```
    docker run -it -d \
      -p 8181:80 -p 8122:22 -p 4075:4075 \
      -v /Users/yourname/dev/:/root/workspace/ \
      --name sming \
      fernandopasse/sming-docker
    ```

3. Using Netbean to setup remote build

   1. In the Services column (in the left sidebar, besides `Projects` and `Files`) , 
   2. Add C/C++ Build Hosts: `localhost` with port `8122`, password is `root`
   3. Access project files via `SFTP` (this will copy the files to remote host)

4. Do `Build and Clean`, It should succeed

5. Make using `Makefile-copy-out.mk`(which is from repo). it does make and copy the binary to the workspace. Now you should be able to see the binaries in your workspace

6. run `flash.sh` to flash the firmware to the device

7. Now run `screen.sh` ,you should be able to see the debug message

   ​

##### The problems we came crossed

1. Use right USB serial cable:  At the beginning I used a cheap cable doesn't support serial communication, the serial doesn't appear under `/dev/` after Installing the driver
2. As the device was used by another project development before, When Connected the device and flashed the firmware, `screen` doesn't respond with the debug message at all, but we can see the device information by command `esptool.py  --port /dev/tty.wchusbserial14510 read_mac` .Even we press the `reset` on the device. What we do is using `esptool.py` to `erase_flash`, and re-flash
3. This problem doesn't block any development but just some noise which can be just ignored. Some gabbage message from the `screen` at the beginning after it is connected, (the debug message is correct though). As the firmware is communicating using default rate(115200), but the initial phase of communication is using a different rate. 


