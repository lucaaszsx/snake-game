# 🐍 Snake Game in C (SDL3)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](./LICENSE)
![C](https://img.shields.io/badge/Language-C-blue.svg)
![SDL3](https://img.shields.io/badge/SDL-3-green.svg)
[![Build](https://img.shields.io/badge/Build-Makefile-orange.svg)](#build--run)

A classic **Snake Game** implementation written in **pure C** using **SDL3** for graphics, input handling and timing.

---

## ✨ Features

- Minimalist and lightweight
- Collision detection (self and wall)
- Keyboard input for snake control

---

## 📦 Requirements

To build and run this project on your machine, make sure you have the following installed:

- **GNU Make**
- **GCC**
- **SDL3 development libraries**
- **pkg-config**

---

## ⚙️ Installation

On Debian/Ubuntu-based systems:

```bash
sudo apt install gcc make libsdl3-dev pkg-config
```

On Fedora:

```bash
sudo dnf install gcc make SDL3-devel pkg-config
```

---

## 📥 Clone the Repository

Clone this repository to your local machine using:

```bash
git clone https://github.com/lucaaszsx/snake-game.git
cd snake-game
```

---

## 🚀 Build & Run

Build:

```bash
make
```

Run:

```bash
make run
```

Clean:

```bash
make clean
```

---

## 🎮 Controls

| Key         | Action       |
|-------------|--------------|
| Arrows / WASD | Move snake |

---

## 📜 License

This project is licensed under the **MIT License**.  
Do whatever you want with it, just give credit if you share.  
See **[LICENSE](./LICENSE)** for full license text.
