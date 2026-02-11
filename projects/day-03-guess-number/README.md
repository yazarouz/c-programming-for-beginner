# Number Guessing Game

A simple terminal-based number guessing game written in C. The computer generates a random number between 1 and 100, and the player has 7 attempts to guess it correctly.

## 🎯 Features
- Random number generation (1–100)
- 7 limited attempts with clear feedback
- Intuitive hints ("Too low" / "Too high")
- Attempt counter and remaining attempts display
- Clean ASCII-art styled UI

## 🛠️ Compilation & Execution
```bash
# Compile with GCC
gcc -o guess_game guess_game.c

# Run the game
./guess_game