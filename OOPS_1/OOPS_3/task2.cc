#include <iostream>
using namespace std;

class Product {
private:
    string productName;
    double price;
    float rating;

public:
    // Parameterized constructor
    Product(string name, double p, float r) {
        productName = name;
        price = p;
        rating = r;
    }

    void displayInfo() {
        cout << "Product Name: " << productName << endl;
        cout << "Price: Rs. " << price << endl;
        cout << "Rating: " << rating << "/5" << endl;
    }
};

int main() {
    Product p1("Samsung Galaxy S24", 74999, 4.5);

    p1.displayInfo();

    return 0;
}
