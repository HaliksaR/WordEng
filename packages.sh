#!/bin/bash
BREAK='\033[m'
LCYAN='\033[1;36m'

echo -e "${LCYAN}Install_lib_C${BREAK}"
apt install gcc -qq
apt install libc-dev -qq

echo -e "${LCYAN}Install_GTK+3${BREAK}"
apt install libgtk-3-dev -qq

echo -e "${LCYAN}Go Install_WordEng!${BREAK}"