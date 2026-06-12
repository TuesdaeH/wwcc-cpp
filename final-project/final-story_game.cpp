/*
 * Interactive Story Game - Outbreak: Escape From Lab Zero
 * Author: Tuesdae Hunter
 * Date: June 11, 2026
 *
 * ==== Project Features ====
 * Variables (3+ types): Lines 37, 38, 40, 41
 * If/else: Lines 121, 154
 * Loop: Lines 69, 121
 * Function w/ return value: Line 101
 * Void function: Line 87
 * Function w/ parameters: Line 87
 * Vector or array: Lines 34, 40
 * Struct or class: Lines 30, 36
 * Enum: Line 30
 * File reading: Lines 51, 69
 * File writing: Lines 94, 95
 * Modern feature 1 (lambda): Line 56
 * Modern feature 2 (range-based for): Lines 89, 134
 * ==========================
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <limits>

using namespace std;

enum class GameState { PLAYING, WIN, LOSE };

struct Room {
    string id;
    string description;
    vector<string> exits;
    bool visited = false;
};

struct Player {
    string name;
    int health = 100;
    vector<string> inventory;
    string currentRoom = "QUARANTINE_CELL";
};

void printBanner();
void printRoom(const Room& r);
bool hasItem(const Player& p, const string& item);
void saveLog(const vector<string>& log, const string& ending);
Room* findRoom(vector<Room>& rooms, const string& id);

vector<Room> loadRooms(const string& filename) {
    vector<Room> rooms;
    ifstream file(filename);
    if (!file) {
        cerr << "Could not open " << filename << "\n";
        return rooms;
    }

    auto getExits = [](const string& id) -> vector<string> {
        if (id == "QUARANTINE_CELL")  return {"north", "east"};
        if (id == "HALLWAY")          return {"west", "north", "east"};
        if (id == "LAB_B")            return {"south", "north"};
        if (id == "SECURITY_OFFICE")  return {"west"};
        if (id == "ROOF")             return {};
        return {};
    };

    string line;
    Room current;
    bool readingDesc = false;

    while (getline(file, line)) {
        if (line.empty()) {
            if (!current.id.empty()) {
                rooms.push_back(current);
                current = Room();
                readingDesc = false;
            }
        } else if (!readingDesc) {
            current.id = line;
            current.exits = getExits(line);
            readingDesc = true;
        } else {
            current.description += line + " ";
        }
    }
    if (!current.id.empty()) rooms.push_back(current);
    return rooms;
}

void printBanner() {
    cout << "=============================================\n";
    cout << "       OUTBREAK: ESCAPE FROM LAB ZERO\n";
    cout << "=============================================\n\n";
}

void printRoom(const Room& r) {
    cout << "\n[ " << r.id << " ]\n";
    cout << r.description << "\n";
    cout << "Exits: ";
    for (const auto& e : r.exits) cout << e << "  ";
    cout << "\n";
}

bool hasItem(const Player& p, const string& item) {
    return find(p.inventory.begin(), p.inventory.end(), item) != p.inventory.end();
}

void saveLog(const vector<string>& log, const string& ending) {
    ofstream out("game_log.txt");
    out << "=== GAME LOG ===\n";
    for (const auto& entry : log) out << entry << "\n";
    out << "\nEnding: " << ending << "\n";
    cout << "\nGame log saved to game_log.txt\n";
}

Room* findRoom(vector<Room>& rooms, const string& id) {
    for (auto& r : rooms)
        if (r.id == id) return &r;
    return nullptr;
}

int main() {
    printBanner();

    vector<Room> rooms = loadRooms("rooms.txt");
    if (rooms.empty()) {
        cout << "Error: rooms.txt not found.\n";
        return 1;
    }

    Player player;
    cout << "Enter your name, survivor: ";
    cin >> player.name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nWelcome, " << player.name << ". Find the antidote and escape.\n";

    GameState state = GameState::PLAYING;
    vector<string> log;
    string command;
    bool keypadSolved = false;

    log.push_back("Player: " + player.name);

    while (state == GameState::PLAYING) {
        Room* room = findRoom(rooms, player.currentRoom);
        if (room == nullptr) { cout << "Error: room not found.\n"; break; }

        if (!room->visited) {
            printRoom(*room);
            room->visited = true;
        } else {
            cout << "\n[You are in " << room->id << "]\n";
            cout << "Exits: ";
            for (const auto& e : room->exits) cout << e << "  ";
            cout << "\n";
        }

        if (!player.inventory.empty()) {
            cout << "Inventory: ";
            for (const auto& i : player.inventory) cout << i << "  ";
            cout << "\n";
        }

        cout << "\n> ";
        getline(cin, command);
        transform(command.begin(), command.end(), command.begin(), ::tolower);
        log.push_back("> " + command);

        if (command == "go north" || command == "north") {
            if (find(room->exits.begin(), room->exits.end(), "north") == room->exits.end()) {
                cout << "You can't go that way.\n";
            } else if (player.currentRoom == "QUARANTINE_CELL") {
                player.currentRoom = "HALLWAY";
            } else if (player.currentRoom == "HALLWAY") {
                player.currentRoom = "LAB_B";
            } else if (player.currentRoom == "LAB_B") {
                if (!hasItem(player, "keycard")) {
                    cout << "A keypad blocks the door. You need a keycard AND the code.\n";
                } else if (!keypadSolved) {
                    cout << "Swipe keycard accepted. Enter 4-digit code: ";
                    string code;
                    getline(cin, code);
                    log.push_back("Code attempt: " + code);
                    if (code == "2479") {
                        cout << "\nACCESS GRANTED. The roof hatch opens!\n";
                        keypadSolved = true;
                        player.currentRoom = "ROOF";
                    } else {
                        cout << "WRONG CODE. An alarm blares. You lose 30 health!\n";
                        player.health -= 30;
                        if (player.health <= 0) {
                            cout << "\nYou collapse. Security drones finish the job. GAME OVER.\n";
                            state = GameState::LOSE;
                        }
                    }
                } else {
                    player.currentRoom = "ROOF";
                }
            }
        } else if (command == "go south" || command == "south") {
            if (player.currentRoom == "LAB_B") player.currentRoom = "HALLWAY";
            else cout << "You can't go that way.\n";
        } else if (command == "go east" || command == "east") {
            if (player.currentRoom == "QUARANTINE_CELL") {
                cout << "The vent is too small. You need to find another way.\n";
            } else if (player.currentRoom == "HALLWAY") {
                player.currentRoom = "SECURITY_OFFICE";
            } else {
                cout << "You can't go that way.\n";
            }
        } else if (command == "go west" || command == "west") {
            if (player.currentRoom == "SECURITY_OFFICE") player.currentRoom = "HALLWAY";
            else cout << "You can't go that way.\n";
        } else if (command == "take keycard" || command == "get keycard") {
            if (player.currentRoom == "SECURITY_OFFICE" && !hasItem(player, "keycard")) {
                player.inventory.push_back("keycard");
                cout << "You grab the keycard and note: code is 2-4-7-9.\n";
            } else if (hasItem(player, "keycard")) {
                cout << "You already have it.\n";
            } else {
                cout << "There's no keycard here.\n";
            }
        } else if (command == "take antidote") {
            if (player.currentRoom == "LAB_B" && !hasItem(player, "antidote")) {
                player.inventory.push_back("antidote");
                cout << "You find a vial labeled ANTIDOTE and pocket it.\n";
            } else {
                cout << "There's nothing to take here.\n";
            }
        } else if (command == "look" || command == "examine") {
            printRoom(*room);
        } else if (command == "status" || command == "health") {
            cout << "Health: " << player.health << "/100\n";
        } else if (command == "quit" || command == "exit") {
            cout << "You give up and wait for the end...\n";
            state = GameState::LOSE;
        } else {
            cout << "Unknown command. Try: north/south/east/west, take <item>, look, status, quit\n";
        }

        if (player.currentRoom == "ROOF") {
            cout << "\nYou burst onto the roof. Fresh air. A helicopter circles overhead.\n";
            cout << "You fire a flare. The helicopter banks toward you.\n";
            if (hasItem(player, "antidote")) {
                cout << "You hold up the antidote vial. They see it. YOU WIN!\n";
                saveLog(log, "WIN - escaped with antidote");
            } else {
                cout << "You escaped, but the antidote is still inside. A partial victory.\n";
                saveLog(log, "ESCAPE - no antidote");
            }
            state = GameState::WIN;
        }

        if (state == GameState::LOSE) {
            saveLog(log, "LOSE");
        }
    }

    return 0;
}