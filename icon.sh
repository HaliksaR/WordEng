#!/bin/bash
BREAK='\033[m'     # ${BREAK} все атрибуты по умолчанию
LCYAN='\033[1;36m' # ${LCYAN} цвет волны

current_dir=$(pwd)

echo "[Desktop Entry]
Version=1.0
Name=WordEng
Exec=$current_dir/bin/WordEng -ui
Path=$current_dir/
Icon=$current_dir/data/style/img/logo.svg
Terminal=false
Type=Application
Categories=Gtk+3;Application;" > /home/$USER/Desktop/WordEng.desktop

chmod +x /home/$USER/Desktop/WordEng.desktop

echo -e "${LCYAN}|----------------------\\ ${BREAK}"
echo -e "${LCYAN}|Create icon on desktop |${BREAK}"
echo -e "${LCYAN}|----------------------/ ${BREAK}"
