#!/bin/bash
BREAK='\033[m'
LCYAN='\033[1;36m'
current_dir=$(pwd)
desktop_path=$(xdg-user-dir DESKTOP)

echo "[Desktop Entry]
Version=1.0
Name=WordEng
Exec=$current_dir/bin/WordEng
Path=$current_dir/
Icon=$current_dir/data/style/img/logo.svg
Terminal=false
Type=Application
Categories=Gtk+3;Application;" > $desktop_path/WordEng.desktop
chmod +x $desktop_path/WordEng.desktop
echo -e "${LCYAN}|----------------------\\ ${BREAK}"
echo -e "${LCYAN}|Create icon on desktop |${BREAK}"
echo -e "${LCYAN}|----------------------/ ${BREAK}"