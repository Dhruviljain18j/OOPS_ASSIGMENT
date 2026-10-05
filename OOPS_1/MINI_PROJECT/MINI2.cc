#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Content {
public:
    string title;
    string platform;
    int views;
    string status;

    Content(string t = "", string p = "", int v = 0, string s = "")
        : title(t), platform(p), views(v), status(s) {}

    // Display all details of a Content object
    void displayDetails() const {
        cout << "Title: " << title << endl;
        cout << "Platform: " << platform << endl;
        cout << "Views: " << views << endl;
        cout << "Status: " << status << endl;
    }
};

const string FILE_NAME = "content_list.txt";

// Save a new content item by appending to the file
void addContent() {
    string title, platform, status;
    int views;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter title: ";
    getline(cin, title);

    cout << "Enter platform: ";
    getline(cin, platform);

    cout << "Enter views: ";
    cin >> views;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter status: ";
    getline(cin, status);

    ofstream file(FILE_NAME, ios::app);

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    // Use | as a separator
    file << title << "|" << platform << "|" << views << "|" << status << endl;

    file.close();

    cout << "Content added successfully!\n";
}

// Convert one line from the file into a Content object
Content parseContent(string line) {
    size_t pos1 = line.find('|');
    size_t pos2 = line.find('|', pos1 + 1);
    size_t pos3 = line.find('|', pos2 + 1);

    string title = line.substr(0, pos1);
    string platform = line.substr(pos1 + 1, pos2 - pos1 - 1);
    int views = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
    string status = line.substr(pos3 + 1);

    return Content(title, platform, views, status);
}

// Read all content items from the file
vector<Content> readContents() {
    vector<Content> contents;
    ifstream file(FILE_NAME);

    if (!file) {
        return contents;
    }

    string line;

    while (getline(file, line)) {
        if (!line.empty()) {
            contents.push_back(parseContent(line));
        }
    }

    file.close();

    return contents;
}

// Display content items as a numbered list
void displayContents() {
    vector<Content> contents = readContents();

    if (contents.empty()) {
        cout << "\nNo content ideas found.\n";
        return;
    }

    cout << "\n===== Content List =====\n";

    for (size_t i = 0; i < contents.size(); i++) {
        cout << i + 1 << ". "
             << contents[i].title
             << " - "
             << contents[i].platform
             << endl;
    }
}

// Update status of a selected content item
void updateStatus() {
    vector<Content> contents = readContents();

    if (contents.empty()) {
        cout << "\nNo content ideas available.\n";
        return;
    }

    displayContents();

    int choice;
    cout << "\nEnter content number to update: ";
    cin >> choice;

    if (choice < 1 || choice > static_cast<int>(contents.size())) {
        cout << "Invalid content number.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string newStatus;
    cout << "Enter new status: ";
    getline(cin, newStatus);

    contents[choice - 1].status = newStatus;

    // Overwrite the file with updated data
    ofstream file(FILE_NAME);

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    for (const Content& content : contents) {
        file << content.title << "|"
             << content.platform << "|"
             << content.views << "|"
             << content.status << endl;
    }

    file.close();

    cout << "Status updated successfully!\n";
}

// Delete a selected content item
void deleteContent() {
    vector<Content> contents = readContents();

    if (contents.empty()) {
        cout << "\nNo content ideas available.\n";
        return;
    }

    displayContents();

    int choice;
    cout << "\nEnter content number to delete: ";
    cin >> choice;

    if (choice < 1 || choice > static_cast<int>(contents.size())) {
        cout << "Invalid content number.\n";
        return;
    }

    // Remove selected item
    contents.erase(contents.begin() + (choice - 1));

    // Overwrite the file
    ofstream file(FILE_NAME);

    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    for (const Content& content : contents) {
        file << content.title << "|"
             << content.platform << "|"
             << content.views << "|"
             << content.status << endl;
    }

    file.close();

    cout << "\nContent deleted successfully!\n";

    // Display updated list
    cout << "\n===== Updated Content List =====\n";
    displayContents();
}

// Main console menu
int main() {
    int choice;

    do {
        cout << "\n==============================\n";
        cout << "     CONTENT IDEA MANAGER\n";
        cout << "==============================\n";
        cout << "1. Add New Content\n";
        cout << "2. Display Content List\n";
        cout << "3. Update Content Status\n";
        cout << "4. Delete Content\n";
        cout << "5. Exit\n";
        cout << "==============================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContent();
                break;

            case 2:
                displayContents();
                break;

            case 3:
                updateStatus();
                break;

            case 4:
                deleteContent();
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
