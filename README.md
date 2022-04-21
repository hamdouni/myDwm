# MyDWM, a customized tiled window manager for Debian based Linux.

![screenshot](assets/screenshot.png)

## Based on

* [DWM 6.2](http://dwm.suckless.org/)
  * [Systray patch](http://dwm.suckless.org/patches/systray)
  * [Useless Gap patch](https://dwm.suckless.org/patches/uselessgap/)
  * [Attach Direction patch](https://dwm.suckless.org/patches/attachdirection/)
* [Dmenu 4.5](http://tools.suckless.org/dmenu/)
* [wmname 0.1](http://tools.suckless.org/wmname)
* [slock 1.1](http://tools.suckless.org/slock/)
* [slstatus](https://github.com/drkhsh/slstatus)
* ZSH Shell with [Oh My Zsh](https://ohmyz.sh/) and [Powerlevel10k](https://github.com/romkatv/powerlevel10k)

## Default configuration

* Prefix path = /usr (need root access to install)
* Preinstalled patches : systray and xft
* Font "3270 Nerd Font" size 16
* Autostart programs are in $HOME/.local/bin/dwm-start, last loop for dwm
* Command key mapped on Windows key

* General shortcuts
  * win + e : open x-file-manager (see below how to set alternatives) 
  * win + s : lock screen (type user password to unlock)
  * win + g : open browser
  * win + p : open password manager
  * win + h : reduce main area
  * win + l : enlarge main area
  * win + m : monocle area
  * win + t : tiled area
  * win + ctrl + space  : open tldr menu
  * win + shift + enter : open terminal
  * win + enter         : swap window in main area
  * win + TAB           : focus next area
  * win + shift + TAB   : focus previous area
  * win + shit + c      : close window
  * win + shift + q     : reload dwm
  * PRINTSCREEN         : select an area to screenshot and create a png in home and copy to clipboard (shell script myScreenshot)

* Multimedia keys pilot moc "music on console" and PulseAudio (shell script audio) + fallback for non multimedia keyboard
  * ctrl + F1 : toggle mute/unmute
  * ctrl + F2 : volume down
  * ctrl + F3 : volume up
  * ctrl + F4 : previous song
  * ctrl + F5 : toggle play/pause
  * ctrl + F6 : next song

* VSCode keybindings
  * ctrl + shift + b : show explorer in the sidebar
  * ctrl + shift + x : show extenstion in the sidebar
  * ctrl + shift + f : show search sidebar
  * ctrl + shift + g : show source controle in sidebar
  * ctrl + shift + j : join lines
  * ctrl + j : toggle terminal panel
  * shift + ² : toggle into terminal
  * ctrl + shift + ² : create new terminal

* Vim keybindings (from any mode : insert, normal or visual)
* Ctrl B : Build Go program
* Ctrl R : Run Go program
* Ctrl S : Save the file
* Ctrl F : Find text
* Ctrl H : Replace text
* Ctrl Q : Secure quit
* Ctrl I : Toggle show invisible characters


## Terminal

- st (suckless terminal) with patch alpha for transparency and anysize so the st window take all available place. 
- Tmux as multiplexer (scroll, splitting, etc...) with prefix CTRL+A to differenciate from remote session on default CTRL+B.

## Screen Layout

Configure your screen layout by placing a shell file "main.sh" in the folder ".screenlayout" in your home directory.
If the file exists, it will be executed at xinit, and if not, there is a minimal fall back inside the .xinitrc file.

*TIPS* : you can use arandr to generate the correct screen layout shell command.

## HiDPI display

Change the dpi value with a .dpi file in your home

```sh
cat ~/.dpi
114
``` 

This value will be used to change the .Xresources file.

## Make and install

```sh
./install
```

* Clean unwanted apps and shell scripts.
* Makes and installs the programs in /usr/bin.
* Copy shell scripts in $HOME/.local/bin. (dwm-start, audio, ...)
* Copy dotfiles in $HOME. (backup existings ones).
* Apt-install other apps (xsettingsd, blueman, feh, moc)

## Bump version

```sh
./bumpversion.sh
```

Accept the suggestion (patch increment) or type the new version.
Updates the version in slstatus to be displayed in the status bar.

## Troubleshoot

Linux user : if you got a fatal error on "/usr/include/ft2build.h", not finding "freetype/config/ftheader.h" then create the symbolic link as below :

```sh
sudo ln -s /usr/include/freetype2/freetype/ /usr/include/
```

## How to install new alternative "x-file-manager" ?

For example, to install thunar as an alternative for x-file-manager :

```sh
# For thunar
sudo update-alternatives --install /usr/bin/x-file-manager x-file-manager /usr/bin/thunar 1000
sudo update-alternatives --set x-file-manager /usr/bin/thunar

# For nautilus (install alternative and prevent nautilus to open desktop) 
sudo update-alternatives --install /usr/bin/x-file-manager x-file-manager /usr/bin/nautilus 1000
sudo update-alternatives --set x-file-manager /usr/bin/nautilus
gsettings set org.gnome.desktop.background show-desktop-icons false
```

## How to set the same font in DWM/Xft and in GTK apps ?

For example, if we want the 'Ubuntu Mono' font at size 12 :

```sh
gsettings set org.gnome.desktop.interface monospace-font-name 'Ubuntu Mono 12'
```

