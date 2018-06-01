<div align="center">
<a href="https://github.com/HaliksaR/WordEng">
<img src="https://user-images.githubusercontent.com/35256960/37650164-b57a8ba4-2c66-11e8-9f42-91fd9a7e63f8.png" width="320" height="320" alt="logo"></img>
</a>
</div>

# WordEng (program for learn english for russians)
[![Build Status](https://travis-ci.org/HaliksaR/WordEng.svg?branch=master)](https://travis-ci.org/HaliksaR/WordEng)
## For russians
**WordEng** - это программа которая помогает пополнить ваш вокабулярный запас английского языка. Суть программы состоит следующем: помочь пользователю получать или закреплять знания английского языка, в зависимости от выбранного пользователем уровня сложности словарной базы. Получать статистику об ошибках и выученных словах пользователем.

#### Группы пользователей
Наш проект нацелен на возрастную категорию с 6 лет и выше, т.к. обширный словарный запас важен абсолютно в любом возрасте.
### Required packages:
 - **Fonts Family**
   ```
   Noto Sans, Liberation Sans, Sans Regular
   ```
 - **Ubuntu/Debian**
   ```
    $ sudo apt install gcc
    $ sudo apt install libc-dev
    $ sudo apt install libgtk-3-dev
   ```
 - **Solus**
   ```
    $ sudo eopkg install gcc
    $ sudo eopkg install glibc-devel
    $ sudo eopkg install libgtk-3-devel
   ```
   
### Installation:
1. Clone git repository to your $HOME directory.
   ```bash
   $ git clone https://github.com/HaliksaR/WordEng.git
   ```
2. Open **terminal** in WordEng directory and write this commands:
   ```make
   make sh # command for install required packages (not fonts)
   make # command for install program
   
   make icon # command for create launcher icon on desktop
   # or this commands #
   make console  # command for start console program
   make gtk  # command for start graephics program
   
   # uninstalling the program #
   make delete
   
   # service commands #
   make test # command for start test
   make clean # command for clear bin and build directory
   ```

### TEST MACHINES
   ```bash
   $ lsb_release -a
   ```
   ```bash
   Distributor ID: Ubuntu
   Description:    Ubuntu 18.04 LTS
   Release:        18.04
   Codename:       bionic
   ```
   ```bash
   Distributor ID:	Solus
   Description:	Solus
   Release:	3.9999
   Codename:	shannon
   ```
   ```bash
   Distributor ID: Ubuntu
   Description:    Ubuntu 17.10
   Release:        17.10
   Codename:       artful
   ```
## Developers
<div>
<a href="https://github.com/HaliksaR">
<img src="https://avatars3.githubusercontent.com/u/35256960?s=460&v=4" width="60" height="60" alt="logo"></img>
</a>
<a href="https://github.com/KrackensCorp">
<img src="https://avatars2.githubusercontent.com/u/36221843?s=460&v=4" width="60" height="60" alt="logo"></img>
</a>
<a href="https://github.com/artemka13722">
<img src="https://avatars1.githubusercontent.com/u/36222432?s=460&v=4" width="60" height="60" alt="logo"></img>
</a>
</div>
