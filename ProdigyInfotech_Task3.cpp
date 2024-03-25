#include <iostream>
#include <conio.h> // For _getch() function
using namespace std;

void printStrongNess(string& input) {
    int n = input.length();
    // Checking lower alphabet in string
    bool hasLower = false, hasUpper = false;
    bool hasDigit = false, specialChar = false;
    string normalChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
    for (int i = 0; i < n; i++) {
        if (islower(input[i]))
            hasLower = true;
        if (isupper(input[i]))
            hasUpper = true;
        if (isdigit(input[i]))
            hasDigit = true;
        size_t special = input.find_first_not_of(normalChars);
        if (special != string::npos)
            specialChar = true;
    }
    // Strength of password
    cout << "Strength of password: ";
    if (hasLower && hasUpper && hasDigit && specialChar && (n >= 8))
        cout << "Strong" << endl;
    else if ((hasLower || hasUpper) && specialChar && (n >= 6))
        cout << "Moderate" << endl;
    else
        cout << "Weak" << endl;
}

int main() {
    string input;
    char ch;
    cout << "Enter your password: ";

    // Masking user input
    while (true) {
        ch = _getch(); // Read character without echoing to console
        if (ch == '\r') // If Enter key is pressed, break the loop
            break;
        input.push_back(ch); // Append character to input string
        cout << '*'; // Print asterisk (*) instead of character
    }
    cout << endl; // Move to the next line after masking password input

    printStrongNess(input);
    return 0;
}

