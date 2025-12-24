# Pong Game

A classic Pong game implementation using C++ and the Raylib graphics library.

## Description

This is a recreation of the classic Pong arcade game where you play against a CPU opponent. Control your paddle to hit the ball back and forth, trying to score points by getting the ball past your opponent's paddle.

## Features

- Classic Pong gameplay mechanics
- Player vs CPU mode
- Simple and intuitive controls
- Score tracking for both players
- Smooth 60 FPS gameplay
- AI opponent with automatic ball tracking

## Requirements

- C++ compiler (supporting C++11 or later)
- [Raylib](https://www.raylib.com/) graphics library

## Installation

1. Install Raylib on your system:

   - **Windows**: Download from [Raylib releases](https://github.com/raysan5/raylib/releases)
   - **Linux**: `sudo apt install libraylib-dev`
   - **macOS**: `brew install raylib`

2. Clone or download this repository

3. Compile the game:

   ```bash
   g++ -o pong main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
   ```

   Or on Windows with MinGW:

   ```bash
   g++ -o pong.exe main.cpp -lraylib -lopengl32 -lgdi32 -lwinmm
   ```

4. Run the game:
   ```bash
   ./pong
   ```

## Controls

- **UP Arrow** - Move paddle up
- **DOWN Arrow** - Move paddle down
- **ESC** - Close the game window

## Gameplay

- You control the right paddle
- The CPU controls the left paddle
- The ball bounces off the top and bottom walls
- Score a point when the ball passes your opponent's paddle
- First to reach the target score wins!

## Game Settings

Current configuration:

- Window size: 1280 x 800 pixels
- Ball speed: 7 pixels per frame
- Paddle speed: 6 pixels per frame
- Paddle size: 25 x 120 pixels
- Ball radius: 20 pixels

These values can be modified in the `main()` function to adjust difficulty.

## Code Structure

- `Ball` class - Handles ball movement, collision with walls, and score updates
- `Paddle` class - Player paddle with keyboard controls
- `CPU_Paddle` class - AI opponent that tracks the ball position
- Global score variables for tracking points

## License

This is a learning project. Feel free to use and modify as needed.

## Acknowledgments

Built with [Raylib](https://www.raylib.com/) - A simple and easy-to-use library to enjoy videogames programming.
