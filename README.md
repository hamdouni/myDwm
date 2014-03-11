Based on
--------

* [DWM 6.0](http://dwm.suckless.org/)
* [Dmenu 4.5](http://tools.suckless.org/dmenu/)
* [Systray patch](http://dwm.suckless.org/patches/systray)
* Xft patch : for [dwm](http://dwm.suckless.org/patches/xft) and [dmenu](http://tools.suckless.org/dmenu/patches/xft)

Default configuration
---------------------

* Prefix path = /usr (need root access to install)
* Preinstalled patches : systray and xft
* Command key mapped on Windows key
* Font "Sans" size 12

Usage
-----

        make
        sudo make install

Linux user : if you got a fatal error on "/usr/include/ft2build.h", not finding "freetype/config/ftheader.h" then do the symbolic link below :

        sudo ln -s /usr/include/freetype2/freetype/ /usr/include/


How to install new alternative "x-file-manager" ?
---------------------------------------------------

For example, to install thunar as an alternative for x-file-manager, do the below command :

        sudo update-alternatives --install /usr/bin/x-file-manager x-file-manager /usr/bin/thunar 1000

How to set the same font in DWM/Xft and in GTK apps ?
------------------------------------------------------------

For example, if we want the 'Ubuntu Mono' font at size 12 :

        gsettings set org.gnome.desktop.interface monospace-font-name 'Ubuntu Mono 12'
