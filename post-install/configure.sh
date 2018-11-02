#!/bin/sh

# configure git
git config --global user.name "Brahim Hamdouni"
git config --global user.email "brahim@hamdouni.com"
git config --global push.default simple

# make docker usable withoud sudo
sudo usermod -aG docker $USER
