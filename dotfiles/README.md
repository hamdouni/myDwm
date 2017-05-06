# VIM
VIM is my editor of choice, so install it, and add vundle to manage plugins.

```shell
	sudo apt install vim
	git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/vundle
	vim +PluginInstall +qall
```

* vim-go : [Fatih's awesome vim plugin to code in go](https://github.com/fatih/vim-go)
* vim-air : [Bailey's wonderfull light powerline replacement](https://github.com/vim-airline/vim-airline)
_See vimrc file to see how to declare plugins with vundle._

# Make vim default
```shell
	sudo update-alternatives --config editor 
```
# vim shortcuts (from any mode : insert, normal or visual)
* Ctrl B : Build Go program
* Ctrl R : Run Go program
* Ctrl S : Save the file
* Ctrl F : Find text
* Ctrl H : Replace text
* Ctrl Q : Secure quit
* Ctrl I : Toggle show invisible characters 

# To avoid ssh client to freeze and disconnect
Put the file ssh-config in .ssh/config
```shell
    cp ssh-config ~/.ssh/config
```
