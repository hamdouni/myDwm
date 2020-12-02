#!/bin/sh

nonattachedsession=`tmux list-sessions | grep -v attached | sed -e 's/[ \r\n]//g' | awk -F ':' '{ print $1 }'`
echo "nonattachedsession vaut $nonattachedsession #" | cat -v
if [ -z $nonattachedsession ]
then
	tmux
else
	tmux a -t $nonattachedsession
fi
