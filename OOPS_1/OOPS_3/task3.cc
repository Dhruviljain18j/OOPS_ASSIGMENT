#include <iostream>
using namespace std;

class Movie {
private:
    string movieName;
    string director;
    float rating;

public:
    // Parameterized constructor
    Movie(string name, string dir, float r) {
        movieName = name;
        director = dir;
        rating = r;
    }

    // Copy constructor
    Movie(const Movie &m) {
        movieName = m.movieName;
        director = m.director;
        rating = m.rating;
    }

    void displayInfo() {
        cout << "Movie Name: " << movieName << endl;
        cout << "Director: " << director << endl;
        cout << "Rating: " << rating << "/10" << endl;
    }
};

int main() {
    // Original object
    Movie movie1("Inception", "Christopher Nolan", 8.8);

    // Copy object
    Movie movie2(movie1);

    cout << "Original Movie:" << endl;
    movie1.displayInfo();

    cout << "\nCopied Movie:" << endl;
    movie2.displayInfo();

    return 0;
}
