#!/bin/bash

BREAK='\033[m'
LCYAN='\033[1;36m'

current_dir=$(pwd)

echo -e "${LCYAN}|Delete folder done!|${BREAK}"

rm /home/$USER/Desktop/WordEng.desktop
rm -rf $current_dir
