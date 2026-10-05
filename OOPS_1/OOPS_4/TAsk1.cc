#include <iostream>
using namespace std;

class SocialMediaUser {
protected:
    string username;
    int followers;

public:
    SocialMediaUser(string user, int f) {
        username = user;
        followers = f;
    }

    void displayProfile() {
        cout << "Username: " << username << endl;
        cout << "Followers: " << followers << endl;
    }
};
