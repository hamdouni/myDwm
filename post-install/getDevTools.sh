#!/bin/sh

sudo apt update
for app in apt-transport-https ca-certificates curl software-properties-common
do
    res=$(dpkg-query --show --showformat='${db:Status-Status}\n' $app)
    if [ "$res" != "installed" ]
    then
        sudo apt install -y "$app"
    fi
done

# docker repo
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"
# vs code repo
curl https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > microsoft.gpg
sudo mv microsoft.gpg /etc/apt/trusted.gpg.d/microsoft.gpg
sudo sh -c 'echo "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main" > /etc/apt/sources.list.d/vscode.list'

sudo apt update
sudo apt install -y docker-ce code
sudo usermod -aG docker $USER


