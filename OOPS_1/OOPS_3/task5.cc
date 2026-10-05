#include <iostream>
#include <fstream>
using namespace std;

class Playlist {
private:
    string playlistName;

public:
    // Constructor
    Playlist() {
        playlistName = "My Favourites";
        cout << "Playlist created: " << playlistName << endl;
    }

    // Destructor
    ~Playlist() {
        ofstream file("autosave.txt");

        file << playlistName;

        file.close();

        cout << "Playlist automatically saved to autosave.txt" << endl;
    }
};

int main() {
    Playlist p1;

    return 0;
}
