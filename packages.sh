#!/bin/bash
BREAK='\033[m'
LCYAN='\033[1;36m'
OS=$(lsb_release -is)

if [ "${OS}" == "Ubuntu" ] || [ "${OS}" = "Debian" ]; then 
    echo -e "${LCYAN}Install_lib_C${BREAK}"
    apt install gcc -qq
    apt install libc-dev -qq
    echo -e "${LCYAN}Install_GTK+3${BREAK}"
    apt install libgtk-3-dev -qq
    echo -e "${LCYAN}Go Install_WordEng!${BREAK}"
elif [ "{$OS}" == "Solus" ]; then 
    echo -e "${LCYAN}Install_lib_C${BREAK}"
    eopkg install gcc
    eopkg  install libc-devel
    echo -e "${LCYAN}Install_GTK+3${BREAK}"
    eopkg install libgtk-3-devel
    echo -e "${LCYAN}Go Install_WordEng!${BREAK}"
elif [ "{$OS}" == "Arch" ] || [ "{$OS}" == "Arch linux" ]; then 
    echo -e "${LCYAN}Install_lib_C${BREAK}"
    pacman -S gcc
    pacman -S libc-devel
    echo -e "${LCYAN}Install_GTK+3${BREAK}"
    pacman -S gtk3
    echo -e "${LCYAN}Go Install_WordEng!${BREAK}"
elif [ "{$OS}" == "RedHat" ] || [ "{$OS}" == "CentOS" ] || [ "{$OS}" == "Fedora" ]; then 
    echo -e "${LCYAN}Install_lib_C${BREAK}"
    yum install gcc
    yum install libc-devel
    echo -e "${LCYAN}Install_GTK+3${BREAK}"
    yum install gtk3-devel
    echo -e "${LCYAN}Go Install_WordEng!${BREAK}"
else 
    echo -e "${LCYAN}I DONT KNOW THIS OS${BREAK}"
fi
