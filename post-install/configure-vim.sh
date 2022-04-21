#!/bin/sh

# install vundle as vim plugin manager then install plugins defined in .vimrc
# vim-go : [Fatih's awesome vim plugin to code in go](https://github.com/fatih/vim-go)
# vim-air : [Bailey's wonderfull light powerline replacement](https://github.com/vim-airline/vim-airline)

git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
vim +PluginInstall +qall

# set as default editor
sudo update-alternatives --set editor /usr/bin/vim.basic

