#!/bin/sh

# make pcmanfm default file manager
sudo update-alternatives --quiet --remove-all x-file-manager 2>/dev/null
sudo update-alternatives --quiet --install /usr/bin/x-file-manager x-file-manager /usr/bin/pcmanfm 1000
sudo update-alternatives --quiet --set x-file-manager /usr/bin/pcmanfm
xdg-mime default Pcmanfm.desktop inode/directory
