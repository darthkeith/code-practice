//-----------------------------------------------------------------------------
// Problem: Implement an algorithm to determine if a string has all unique
// characters.
//
// Notes: Used a hash set.
//-----------------------------------------------------------------------------

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    string input;
    unordered_set<char> charSet;

    cout << "Enter string: ";
    getline(cin, input);
    cout << "You typed: " << input << endl;

    for (char c : input) {
        if (charSet.contains(c)) {
            cout << "Repeated character: " << c << endl;
            return 0;
        }
        charSet.insert(c);
    }
    cout << "All unique characters" << endl;
    return 0;
}

