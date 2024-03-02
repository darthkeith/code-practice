//-----------------------------------------------------------------------------
// Problem: Determine whether one string can be changed into another by
//          performing one or zero of the following edits: insert, remove, or
//          replace a single character.
//-----------------------------------------------------------------------------

#include<iostream>

bool one_away(std::string&, std::string&);
bool one_replace(std::string&, std::string&);
bool one_insert(std::string&, std::string&);

int main() {
    std::string str1;
    std::string str2;
    std::cout << "Enter two strings: ";
    std::cin >> str1;
    std::cin >> str2;
    std::cout << "String 1: " << str1 << std::endl;
    std::cout << "String 2: " << str2 << std::endl;

    if (!one_away(str1, str2))
        std::cout << "Not ";
    std::cout << "One Away" << std::endl;

    return 0;
}

// Return if one string is one edit away from the other.
bool one_away(std::string& s, std::string& t) {
    int diff = t.length() - s.length();
    if (diff == 0)
        return one_replace(s, t);
    if (diff == 1)
        return one_insert(s, t);
    if (diff == -1)
        return one_insert(t, s);
    return false;
}

// Return if two strings of equal length differ in at most one index.
bool one_replace(std::string& s, std::string& t) {
    bool found_replace = false;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] != t[i]) {
            if (found_replace)
                return false;
            found_replace = true;
        }
    }
    return true;
}

// Return if a character can be inserted into the 1st string to get the 2nd.
// Assume that the second string is one character longer than the first.
bool one_insert(std::string& s, std::string& t) {
    bool found_insert = false;
    size_t i = 0;
    size_t j = 0;
    while (i < s.length()) {
        if (s[i] != t[j]) {
            if (found_insert)
                return false;
            found_insert = true;
        } else
            i++;
        j++;
    }
    return true;
}

