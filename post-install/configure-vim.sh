#!/bin/sh

# install plugins with vim-plug
vim -c "PlugInstall" -c "qa"

# install coc completion languages
vim -c  "CocInstall -sync coc-go coc-tsserver coc-svelte coc-html coc-css coc-json|q" -c "qa"

# set as default editor
sudo update-alternatives --set editor /usr/bin/vim.basic

