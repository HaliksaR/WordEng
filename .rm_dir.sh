#!/bin/bash

BREAK='\033[m'     # ${BREAK} все атрибуты по умолчанию
LCYAN='\033[1;36m' # ${LCYAN} цвет волны

current_dir=$(pwd)

echo -e "${LCYAN}|Delete folder done!|${BREAK}"

rm /home/$USER/Desktop/WordEng.desktop
rm -rf $current_dir
