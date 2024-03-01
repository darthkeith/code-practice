//-----------------------------------------------------------------------------
// Problem: Implement an algorithm to determine if a string has all unique
// characters.
//-----------------------------------------------------------------------------

#include <iostream>
#include <unordered_set>

int main() {
    std::string input;
    std::unordered_set<char> charSet;

    std::cout << "Enter string: ";
    std::getline(std::cin, input);
    std::cout << "You typed: " << input << std::endl;

    for (char c : input) {
        if (charSet.contains(c)) {
            std::cout << "Repeated character: " << c << std::endl;
            return 0;
        }
        charSet.insert(c);
    }
    std::cout << "All unique characters" << std::endl;

    return 0;
}

