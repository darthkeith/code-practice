//-----------------------------------------------------------------------------
// Problem: Determine if a string is a permutation of a palindrome, ignoring
//          whitespace.
//-----------------------------------------------------------------------------

#include<iostream>
#include<unordered_set>
#include<cctype>

bool is_perm_palin(std::string&);

int main() {
    std::string str;
    std::cout << "Enter string: ";
    std::getline(std::cin, str);

    if (!is_perm_palin(str))
        std::cout << "Not ";
    std::cout << "Permutation of Palindrome" << std::endl;

    return 0;
}

bool is_perm_palin(std::string& s) {
    std::unordered_set<char> unmatched;

    for (char c : s) {
        if (std::isspace(c))
            continue;
        if (unmatched.contains(c)) 
            unmatched.erase(c);
        else
            unmatched.insert(c);
    }

    if (unmatched.size() > 1)
        return false;
    return true;
}

