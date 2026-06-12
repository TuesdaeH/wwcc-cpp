# Outbreak: Escape From Lab Zero

## How to Play
Compile and run the game:
  g++ -std=c++17 -Wall final-story_game.cpp -o story_game
  ./story_game (Mac/Linux) or .\story_game (Windows)

Enter your name when prompted, then use text commands to navigate.

## Commands
- north / go north
- south / go south
- east / go east
- west / go west
- take keycard
- take antidote
- look
- status
- quit

## Goal
Wake up in a quarantine cell, find the antidote, get the keycard,
crack the keypad code, and escape to the roof.

## Winning
Get the keycard from the Security Office, grab the antidote from Lab B,
then use the keypad code (found on the sticky note) to reach the roof.

## C++ Features Used
- enum class GameState (enum)
- struct Room and struct Player (structs)
- vector<string> for inventory and exits (vectors)
- ifstream to read rooms.txt (file reading)
- ofstream to write game_log.txt (file writing)
- Lambda function for exit mapping
- Range-based for loops
- auto for type deduction
- nullptr check for room pointer

## Files
- final-story_game.cpp - main source code
- rooms.txt - room descriptions loaded at runtime
- game_log.txt - generated when the game ends
- README.md - this file