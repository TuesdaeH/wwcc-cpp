#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int NUM_SONGS = 5;

struct Artist {
    string name;
    string hometown;
};

struct Song {
    string title;
    Artist artist;
    string genre;
    int durationSeconds;
};

string formatDuration(int seconds) {
    int minutes = seconds / 60;
    int secs = seconds % 60;
    string secStr = (secs < 10) ? "0" + to_string(secs) : to_string(secs);
    return to_string(minutes) + ":" + secStr;
}

string toLower(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

int main() {
    Song playlist[NUM_SONGS];

    cout << "PERSONAL PLAYLIST MANAGER" << endl;
    cout << "--------------------------" << endl;

    // Get song info
    for (int i = 0; i < NUM_SONGS; i++) {
        cout << "\nEnter information for Song " << i + 1 << ":" << endl;
        cout << "  Title: ";
        getline(cin, playlist[i].title);
        cout << "  Artist name: ";
        getline(cin, playlist[i].artist.name);
        cout << "  Artist hometown: ";
        getline(cin, playlist[i].artist.hometown);
        cout << "  Genre: ";
        getline(cin, playlist[i].genre);
        cout << "  Duration (seconds): ";
        cin >> playlist[i].durationSeconds;
        cin.ignore();
    }

    // Display playlist
    cout << "\nYOUR PLAYLIST:" << endl;
    cout << "--------------" << endl;
    for (int i = 0; i < NUM_SONGS; i++) {
        cout << i + 1 << ". " << playlist[i].title << endl;
        cout << "   Artist: " << playlist[i].artist.name << " (" << playlist[i].artist.hometown << ")" << endl;
        cout << "   Genre: " << playlist[i].genre << endl;
        cout << "   Duration: " << formatDuration(playlist[i].durationSeconds) << endl;
        cout << endl;
    }

    // Total runtime and longest song
    int totalSeconds = 0;
    int longestIndex = 0;
    for (int i = 0; i < NUM_SONGS; i++) {
        totalSeconds += playlist[i].durationSeconds;
        if (playlist[i].durationSeconds > playlist[longestIndex].durationSeconds) {
            longestIndex = i;
        }
    }

    cout << "Playlist Stats:" << endl;
    cout << "  Total runtime: " << formatDuration(totalSeconds) << endl;
    cout << "  Longest song:  " << playlist[longestIndex].title << " (" << formatDuration(playlist[longestIndex].durationSeconds) << ")" << endl;

    // Search by artist
    string artistSearch;
    cout << "\nSearch by artist: ";
    getline(cin, artistSearch);
    bool artistFound = false;
    cout << "Songs by " << artistSearch << ":" << endl;
    for (int i = 0; i < NUM_SONGS; i++) {
        if (toLower(playlist[i].artist.name) == toLower(artistSearch)) {
            cout << "  - " << playlist[i].title << " (" << formatDuration(playlist[i].durationSeconds) << ")" << endl;
            artistFound = true;
        }
    }
    if (!artistFound) cout << "  No songs found for that artist." << endl;

    // Search by genre
    string genreSearch;
    cout << "\nSearch by genre: ";
    getline(cin, genreSearch);
    bool genreFound = false;
    cout << "Songs in genre \"" << genreSearch << "\":" << endl;
    for (int i = 0; i < NUM_SONGS; i++) {
        if (toLower(playlist[i].genre) == toLower(genreSearch)) {
            cout << "  - " << playlist[i].title << " (" << formatDuration(playlist[i].durationSeconds) << ")" << endl;
            genreFound = true;
        }
    }
    if (!genreFound) cout << "  No songs found for that genre." << endl;

    return 0;
}