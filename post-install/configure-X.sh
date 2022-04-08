#!/bin/sh

# default path for X Desktop protocol
xdg-user-dirs-update --set DESKTOP $HOME
xdg-user-dirs-update --set DOWNLOAD $HOME
xdg-user-dirs-update --set TEMPLATES $HOME
xdg-user-dirs-update --set PUBLICSHARE $HOME
xdg-user-dirs-update --set DOCUMENTS $HOME
xdg-user-dirs-update --set MUSIC $HOME
xdg-user-dirs-update --set PICTURES $HOME
xdg-user-dirs-update --set VIDEOS $HOME

# dpi configuration via .dpi file
# read the .dpi and change Xresources file
if [ -e ~/.dpi ]; then 
    dpi=`cat ~/.dpi | tr -d "\n "`
    sed -i "s/Xft.dpi: [0-9]*/Xft.dpi: $dpi/" ~/.Xresources
fi
