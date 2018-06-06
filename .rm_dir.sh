#!/bin/bash

BREAK='\033[m'
LCYAN='\033[1;36m'

current_dir=$(pwd)
desktop_path=$(xdg-user-dir DESKTOP)

rm $desktop_path/WordEng.desktop
rm -rf $current_dir
echo -e "${LCYAN}|Delete folder done!|${BREAK}"
