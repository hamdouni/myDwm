# CONFIG FILES

## apps.list

List of debian packages to install. 
One package name by line.

## configs.list

List of configuration files, for each line :

```
filename:filepath
```

with "filename" is the name of the configuration file in "dotfiles" folder and "filepath" is the destination file path for this configuration, relative to $HOME.

## webapps.list

Install all desktop webapps with a chromium shell in $HOME/.local/bin with the appropriate dwm tag.

```
webappname;tag;url
```

with "webappname" the name of the webapp in $HOME/.local/bin, "tag" the dwm tag destination, "url" the webapp url.
