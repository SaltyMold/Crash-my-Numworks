<h1 align="center">Application to Crash the Numworks Calculator</h1>
<p align="center">
    <img alt="Version" src="https://img.shields.io/badge/Version-0.0.4-blue?style=for-the-badge&color=blue">
    <img alt="Stars" src="https://img.shields.io/github/stars/SaltyMold/Crash-my-Numworks?style=for-the-badge&color=magenta">
    <img alt="Forks" src="https://img.shields.io/github/forks/SaltyMold/Crash-my-Numworks?color=cyan&style=for-the-badge&color=purple">
    <img alt="License" src="https://img.shields.io/github/license/SaltyMold/Crash-my-Numworks?style=for-the-badge&color=blue">
    <br>
    <a href="https://github.com/SaltyMold"><img title="Developer" src="https://img.shields.io/badge/Developer-SaltyMold-red?style=flat-square"></a>
    <img alt="Maintained" src="https://img.shields.io/badge/Maintained-No-blue?style=flat-square">
    <img alt="Written In" src="https://img.shields.io/badge/Written%20In-C-yellow?style=flat-square">
</p>

_This app is designed to voluntarily crash the **NumWorks calculator**._


## Install the app

To install this app, you'll need to:
1. Download the latest **`Crash-my-Numworks.nwa`** file from the **[Releases](https://github.com/SaltyMold/Crash-my-Numworks/releases)** page
3. Connect your **NumWorks calculator** to your computer using a USB cable.  
4. Head to **[my.numworks.com/apps](https://my.numworks.com/apps)** to send the **`nwa`** file on your **calculator**.

## How to use the app

| Version  | v0.0.1 | v0.0.2 | v0.0.3 | v0.0.4 |
|----------|--------|--------|--------|--------|
| **Description** | Click on the Application, this will Crash and Reset your Numworks. | Click on the app, then press home to exit or nine to crash. | I added a funny ending | You need to hold insted of crash + funny ending. |
| **Screenshot** | <img src="https://github.com/user-attachments/assets/8d90b405-dafb-4c20-b2fd-8b596124ba01" width="200" alt="Crash-my-Numworks"> | <img src="https://github.com/user-attachments/assets/6edb1597-2885-45de-9d64-34194922e8ae" width="200" alt="Crash-my-Numworks2"> | <img src="https://github.com/user-attachments/assets/280d4984-8ba7-4239-a44f-baaceaa5317c" width="200" alt="Crash-my-Numworks3"> | <img src="https://github.com/user-attachments/assets/727d5ae8-933c-4cc7-a94e-6c71e78b0e6e" width="200" alt="Crash-my-Numworks4"> |

## Build the app

To build this sample app, you will need to install the **[embedded ARM toolchain](https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain)** and **[Node.js](https://nodejs.org/en/) 18**. The C SDK for Epsilon apps is shipped as an **npm module called [nwlink](https://www.npmjs.com/package/nwlink) v0.0.16**.

### Debian

```sh
sudo apt install -y build-essential git gcc-arm-none-eabi binutils-arm-none-eabi nodejs npm && npm install -g n && sudo n 18 && npm install -g nwlink@0.0.16
git clone https://github.com/SaltyMold/Crash-my-Numworks.git
cd Crash-my-Numworks
make clean && make build
```

### Windows

Install msys2 from [the MSYS2 Github](https://github.com/msys2/msys2-installer/releases/download/2025-02-21/msys2-x86_64-20250221.exe) and open the msys2.exe file.
Download the .zip from [the Node Github](https://github.com/actions/node-versions/releases/download/18.20.7-13438827950/node-18.20.7-win32-x64.7z), and extract it.

```sh
#MSYS2

pacman -Syu

#Replace with the reel node path
echo 'export PATH="/c/Users/UserName/AppData/Local/Programs/node-18.20.7-win32-x64:$PATH"' >> ~/.bashrc
source ~/.bashrc

npm install -g nwlink@0.0.16
nwlink --version
```

```ps
#PowerShell

#You can chose a diferent path
$env:ChocolateyInstall = "$env:LOCALAPPDATA\Programs\choco"
[System.Environment]::SetEnvironmentVariable("ChocolateyInstall", $env:ChocolateyInstall, "User")

Set-ExecutionPolicy Bypass -Scope Process -Force
[System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))

$env:Path += ";$env:ChocolateyInstall\bin"
[System.Environment]::SetEnvironmentVariable("Path", $env:Path, "User")
choco --version

choco install make --version=4.3 -y --force
make --version
```

```sh
#MSYS2

#Replace with the reel make path
echo 'export PATH="/c/Users/UserName/AppData/Local/Programs/choco/make/bin:$PATH"' >> ~/.bashrc 
source ~/.bashrc

pacman -S --noconfirm mingw-w64-x86_64-arm-none-eabi-gcc
arm-none-eabi-gcc --version

pacman -S --noconfirm git
git --version
git clone https://github.com/SaltyMold/Crash-my-Numworks.git

cd Crash-my-Numworks
make clean && make build
```

You should now have a **`output/app.nwa` file** that you can distribute! Anyone can now install it on their calculator from the **[NumWorks online uploader](https://my.numworks.com/apps)**.

## How I created this application

This code attempts to crash the calculator by writing to an invalid memory address (0xFFFFFFFF).

## Build your own app

To build your own app, start by cloning the repository:

```sh
git clone https://github.com/SaltyMold/Crash-my-Numworks.git
```
Inside the project, you'll find `eadk.h`, which provides **essential functions** for interacting with the **[calculator](https://en.wikipedia.org/wiki/NumWorks)**. Modify `main.c` to implement your own code.
Additionally, make sure to include an `icon.png` with dimensions **55×56 pixels** to serve as your **app’s icon**. Once your modifications are done, link the app with **[nwlink](https://www.npmjs.com/package/nwlink)** and enjoy your app!

## Special thanks 

I followed the guide from [epsilon-sample-app-c](https://github.com/numworks/epsilon-sample-app-c) to build this app.
