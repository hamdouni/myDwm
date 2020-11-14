#!/bin/sh

# configure git
git config --global user.name "Brahim Hamdouni"
git config --global user.email "brahim@hamdouni.com"
git config --global push.default simple

# make docker usable withoud sudo
sudo usermod -aG docker $USER

# make st my default
sudo update-alternatives --quiet --install /usr/bin/x-terminal-emulator x-terminal-emulator /usr/bin/st 1000
sudo update-alternatives --quiet --set x-terminal-emulator /usr/bin/st

# make pcmanfm default file manager
sudo update-alternatives --quiet --remove-all x-file-manager 2>/dev/null
sudo update-alternatives --quiet --install /usr/bin/x-file-manager x-file-manager /usr/bin/pcmanfm 1000
sudo update-alternatives --quiet --set x-file-manager /usr/bin/pcmanfm
xdg-mime default Pcmanfm.desktop inode/directory

# make firefox my default
sudo update-alternatives --quiet --set x-www-browser /usr/bin/firefox
sudo update-alternatives --quiet --set gnome-www-browser /usr/bin/firefox
xdg-settings set default-web-browser firefox.desktop

# default path for X Desktop protocol
xdg-user-dirs-update --set DESKTOP $HOME
xdg-user-dirs-update --set DOWNLOAD $HOME
xdg-user-dirs-update --set TEMPLATES $HOME
xdg-user-dirs-update --set PUBLICSHARE $HOME
xdg-user-dirs-update --set DOCUMENTS $HOME
xdg-user-dirs-update --set MUSIC $HOME
xdg-user-dirs-update --set PICTURES $HOME
xdg-user-dirs-update --set VIDEOS $HOME
