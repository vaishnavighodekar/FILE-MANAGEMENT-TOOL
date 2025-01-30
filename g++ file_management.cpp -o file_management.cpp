#include <iostream>
#include <fstream>
#include <string>
#include <limits> // For numeric_limits

using namespace std;

void writeToFile(const string& filename) {
    ofstream file(filename.c_str(), ios::out); // Explicitly use c_str() for file path
    if (file.is_open()) {
        string data;
        cout << "Enter text to write to the file (end with a blank line):\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        while (true) {
            getline(cin, data);
            if (data.empty()) break; // Exit on blank line
            file << data << endl;
        }
        file.close();
        cout << "Data written to " << filename << endl;
    } else {
        cout << "Error: Unable to open file for writing.\n";
    }
}

void appendToFile(const string& filename) {
    ofstream file(filename.c_str(), ios::app); // Explicitly use c_str() for file path
    if (file.is_open()) {
        string data;
        cout << "Enter text to append to the file (end with a blank line):\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        while (true) {
            getline(cin, data);
            if (data.empty()) break; // Exit on blank line
            file << data << endl;
        }
        file.close();
        cout << "Data appended to " << filename << endl;
    } else {
        cout << "Error: Unable to open file for appending.\n";
    }
}

void readFromFile(const string& filename) {
    ifstream file(filename.c_str(), ios::in); // Explicitly use c_str() for file path
    if (file.is_open()) {
        string data;
        cout << "Contents of " << filename << ":\n";
        while (getline(file, data)) {
            cout << data << endl;
        }
        file.close();
    } else {
        cout << "Error: Unable to open file for reading.\n";
    }
}

int main() {
    string filename;
    int choice;

    cout << "File Management Tool\n";
    cout << "Enter the name of the text file: ";
    cin >> filename;

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Write to file\n";
        cout << "2. Append to file\n";
        cout << "3. Read from file\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeToFile(filename);
                break;
            case 2:
                appendToFile(filename);
                break;
            case 3:
                readFromFile(filename);
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

