
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

// Your original function, completely untouched
string returnAbb(string s, int start, int end) {
    int l = end - start + 1;

    if (l <= 10) {
        return s.substr(start, l);
    } else {
        string abb = "";
        abb += s[start];
        abb += to_string(l - 2);
        abb += s[end];
        return abb;
    }
}

int main() {
    int numWords;
    
    // 1. Read the first line (the integer n) from the input
    if (!(cin >> numWords)) return 0;

    string s = "";
    string tempWord;
    
    // 2. Read the actual words and build the giant string 's' 
    // separated by newlines, just like your hardcoded string had.
    for (int k = 0; k < numWords; k++) {
        cin >> tempWord;
        s += tempWord;
        if (k < numWords - 1) {
            s += "\n";
        }
    }

    // =========================================================
    // 3. YOUR EXACT ORIGINAL PARSING LOGIC BELOW
    // =========================================================
    string newS = "";
    int start = 0, end = 0, i = 0, n = s.length();

    while (i < n) {
        char cha = s[i];

        if (isalpha(cha)) {
            start = i;

            while (i < n && isalpha(s[i])) {
                i++;
            }

            end = i - 1;

            newS += returnAbb(s, start, end);
        }
        else if (cha == '\n') {
            newS += "\n";
            i++;
        }
        else {
            i++;
        }
    }

    cout << newS << "\n";

    return 0;
}