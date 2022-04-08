#!/bin/sh

# make st my default
sudo update-alternatives --quiet --install /usr/bin/x-terminal-emulator x-terminal-emulator /usr/bin/st 1000
sudo update-alternatives --quiet --set x-terminal-emulator /usr/bin/st
