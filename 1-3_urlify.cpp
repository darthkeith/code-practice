//-----------------------------------------------------------------------------
// Problem: Replace all spaces in a given string with `%20`.
//-----------------------------------------------------------------------------

#include <iostream>

void urlify(std::string&);

int main() {
    std::string str;
    std::cout << "Enter string: ";
    std::getline(std::cin, str);
    urlify(str);
    std::cout << "URLified: " << str << std::endl;

    return 0;
}

void urlify(std::string& s) {
    int spaces = std::count(s.begin(), s.end(), ' ');
    int new_len = 2 * spaces + s.length();
    int i = s.length() - 1;
    int k = new_len - 1;
    s.resize(new_len);
    while (i < k) {
        if (s[i] == ' ') {
            s.replace(k - 2, 3, "%20");
            k -= 3;
        } else {
            s[k] = s[i];
            k--;
        }
        i--;
    }
}

