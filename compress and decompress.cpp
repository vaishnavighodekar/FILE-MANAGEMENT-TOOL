#include <iostream>
#include <string>
#include <sstream> // For ostringstream
using namespace std;

// Function to compress the string using Run-Length Encoding (RLE)
string compressRLE(const string &input) {
    string compressed = "";
    int count = 1;

    for (size_t i = 1; i < input.length(); i++) {
        // Check if the current character is the same as the previous one
        if (input[i] == input[i - 1]) {
            count++;
        } else {
            // Convert the count to string using ostringstream
            ostringstream oss;
            oss << count;
            compressed += oss.str() + input[i - 1];
            count = 1; // Reset the count for the next character
        }
    }

    // Add the last character and its count
    ostringstream oss;
    oss << count;
    compressed += oss.str() + input[input.length() - 1];

    return compressed;
}

// Function to decompress the string using Run-Length Encoding (RLE)
string decompressRLE(const string &input) {
    string decompressed = "";
    int count = 0;

    for (size_t i = 0; i < input.length(); i++) {
        // If the character is a digit, it indicates the count of the character
        if (isdigit(input[i])) {
            count = count * 10 + (input[i] - '0'); // Handle multi-digit numbers
        } else {
            // Append the character 'count' times to the decompressed string
            decompressed.append(count, input[i]);
            count = 0; // Reset the count for the next character
        }
    }
    return decompressed;
}

int main() {
    int choice;
    string input, result;

    cout << "Choose an option:\n";
    cout << "1. Compress a string\n";
    cout << "2. Decompress a string\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    cin.ignore(); // Ignore any newline character left in the input buffer

    if (choice == 1) {
        // Compression
        cout << "Enter the string to compress: ";
        getline(cin, input);
        result = compressRLE(input);
        cout << "Compressed string: " << result << endl;
    } else if (choice == 2) {
        // Decompression
        cout << "Enter the string to decompress: ";
        getline(cin, input);
        result = decompressRLE(input);
        cout << "Decompressed string: " << result << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}

