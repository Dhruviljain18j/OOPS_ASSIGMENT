#include <iostream>
using namespace std;

class Ticket {
public:
    Ticket() {
        cout << "Ticket booked successfully!" << endl;
    }

    // Destructor
    ~Ticket() {
        cout << "Saving your ticket..." << endl;
    }
};

int main() {
    Ticket t1;

    cout << "Ticket object is being used..." << endl;

    // Destructor automatically called when t1 goes out of scope
    return 0;
}
