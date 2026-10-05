#include <iostream>
using namespace std;

class Playlist {
private:
    string playlistName;

public:
    // Default constructor
    Playlist() {
        playlistName = "My Favourites";
        cout << "Welcome to " << playlistName << " playlist!" << endl;
    }
};

int main() {
    Playlist p1;

    return 0;
}
