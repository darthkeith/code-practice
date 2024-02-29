//-----------------------------------------------------------------------------
// Problem: Given two strings, determine if one is a permutation of the other.
//-----------------------------------------------------------------------------

#include <iostream>
#include <unordered_map>

using namespace std;

bool is_permutation(string&, string&);

int main() {
    string str1;
    string str2;
    cout << "Enter two strings: ";
    cin >> str1;
    cin >> str2;
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;

    if (is_permutation(str1, str2))
        cout << "Permutation";
    else
        cout << "Not Permutation";
    cout << endl;

    return 0;
}

bool is_permutation(string& s, string& t) {
    if (s.length() != t.length())
        return false;
    unordered_map<char, int> char_count;
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

