Based on :
* [DWM v6.0](http://dwm.suckless.org/)
* [Dmenu 4.5](http://tools.suckless.org/dmenu/)
* [Systray patch](http://dwm.suckless.org/patches/systray)
* Xft patch : for [dwm](http://dwm.suckless.org/patches/xft) and [dmenu](http://tools.suckless.org/dmenu/patches/xft)

Default configuration :
* Prefix path = /usr (need root access to install)
* Preinstalled patches : systray and xft
* Command key mapped on Windows key
* Font "Sans" size 12

Linux user : if you got a fatal error on "/usr/include/ft2build.h", not finding "freetype/config/ftheader.h" then do the symbolic link below :

        sudo ln -s /usr/include/freetype2/freetype/ /usr/include/


Usage :

        make
        sudo make install
