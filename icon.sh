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
    echo "[Desktop Entry]
    Version=1.0
    Name=WordEng
    Exec=$current_dir/bin/WordEng
    Path=$current_dir/
    Icon=$current_dir/data/style/img/logo.svg
    Terminal=false
    Type=Application
    Categories=Gtk+3;Application;" > /home/$USER/${DESK}/WordEng.desktop
    chmod +x /home/$USER/${DESK}/WordEng.desktop
    echo -e "${LCYAN}|----------------------\\ ${BREAK}"
    echo -e "${LCYAN}|Create icon on desktop |${BREAK}"
    echo -e "${LCYAN}|----------------------/ ${BREAK}"
else
    echo -e "${LCYAN}I NOT FOUND DESKTOP${BREAK}"  
fi