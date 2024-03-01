//-----------------------------------------------------------------------------
// Problem: Given two strings, determine if one is a permutation of the other.
//-----------------------------------------------------------------------------

#include <iostream>
#include <unordered_map>

bool is_permutation(std::string&, std::string&);

int main() {
    std::string str1;
    std::string str2;
    std::cout << "Enter two strings: ";
    std::cin >> str1;
    std::cin >> str2;
    std::cout << "String 1: " << str1 << std::endl;
    std::cout << "String 2: " << str2 << std::endl;

    if (is_permutation(str1, str2))
        std::cout << "Permutation";
    else
        std::cout << "Not Permutation";
    std::cout << std::endl;

    return 0;
}

bool is_permutation(std::string& s, std::string& t) {
    if (s.length() != t.length())
        return false;
    std::unordered_map<char, int> char_count;
    for (char c : s) {
        char_count[c]++;
    }
    for (char c : t) {
        char_count[c]--;
        if (char_count[c] < 0)
            return false;
    }
    return true;
}

