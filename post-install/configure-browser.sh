#!/bin/sh

# make firefox my default
sudo update-alternatives --quiet --set x-www-browser /usr/bin/firefox
sudo update-alternatives --quiet --set gnome-www-browser /usr/bin/firefox
xdg-settings set default-web-browser firefox.desktop
