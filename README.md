brewmaster
=========
Kegerator monitor and tap identifier.

Directories
-----------
- ember_frontend - the JavaScript based web front end. Runs in
the client browser.
- webapi - the Go based web api. Runs on the Raspberry pi.
- examples - experiments that may be useful to keep around during development.

Configuring Raspberri Pi
------------------------
- sudo apt-get install go vim git clang libdispatch-dev cmake libcairo2-dev
- Use raspi-config to use the entire SD card
- Your raspi should be booting to terminal. If it is
booting to X, use raspi-config to change the boot behavior.


