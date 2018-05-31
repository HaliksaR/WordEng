# Travis
 - ### dev [![Build Status](https://travis-ci.org/HaliksaR/WordEng.svg?branch=dev)](https://travis-ci.org/HaliksaR/WordEng)
 - ### HaliksaR [![Build Status](https://travis-ci.org/HaliksaR/WordEng.svg?branch=HaliksaR)](https://travis-ci.org/HaliksaR/WordEng)
 - ### Andrey [![Build Status](https://travis-ci.org/HaliksaR/WordEng.svg?branch=Andrey)](https://travis-ci.org/HaliksaR/WordEng)
 - ### Artem [![Build Status](https://travis-ci.org/HaliksaR/WordEng.svg?branch=Artem)](https://travis-ci.org/HaliksaR/WordEng)
 
<div align="center">
<a href="https://github.com/HaliksaR/WordEng">
<img src="https://user-images.githubusercontent.com/35256960/37650164-b57a8ba4-2c66-11e8-9f42-91fd9a7e63f8.png" width="320" height="320" alt="logo"></img>
</a>
</div>

# WordEng (program for learn english for russians)
### Required packages:
 - **Fonts Family**
   ```
   Noto Sans
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
