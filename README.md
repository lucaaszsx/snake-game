# Snake Game In C (SDL3)

A classic **Snake Game** implementation written in **pure C** using **SDL3** for graphics, input handling and timing.

## Features

- Minimalist and lightweight
- Collision detection (self and wall)
- Keyboard input for snake control

## Requirements

To build and run this project in your machine, make sure you have the following installed:

- **GNU Make**
- **GCC**
- **SDL3 development libs**

### Installation

On Debian/Ubuntu-based systems:

```bash
sudo apt install gcc make libsdl3-dev pkg-config
```

On Fedora:

```bash
sudo dnf install gcc make SDL3-devel pkg-config
```

## Build & Run

Build:

```bash
make
```

Run

```bash
make run
```

Clean

```bash
make clean
```

## Controls

|    Key    |    Action    |
|--------------------------|
| Arrows/WASD | move snake |

## License

This project is licensed under the **MIT License**. Do whatever you want with it, just give credit if you share. See **[LICENSE](./LICENSE)** for full license text.