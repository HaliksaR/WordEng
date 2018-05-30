#!/bin/bash

BREAK='\033[m'
LCYAN='\033[1;36m'

current_dir=$(pwd)

for i in $(ls ~); do
    if [ "${i}" == "Desktop" ]; then 
        DESK=${i}
        break
    elif [ "${i}" == "Рабочий стол" ]; then
        DESK=${i}
        break
    else 
        DESK="0"
    fi
done

if [ "${DESK}" != "0" ]; then 
    echo -e "${LCYAN}|Delete folder done!|${BREAK}"
    rm /home/$USER/${DESK}/WordEng.desktop
    rm -rf $current_dir
else
    echo -e "${LCYAN}I NOT FOUND DESKTOP${BREAK}"  
fi
