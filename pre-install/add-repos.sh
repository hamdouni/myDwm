#!/bin/sh

# docker repo
res=$(dpkg-query --show --showformat='${db:Status-Status}\n' "docker-ce")
if [ "$res" != "installed" ]
then
    curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
    sudo add-apt-repository -y "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
fi

# golang repo
res=$(dpkg-query --show --showformat='${db:Status-Status}\n' "golang-go")
if [ "$res" != "installed" ]
then
    sudo add-apt-repository -y ppa:longsleep/golang-backports
fi
