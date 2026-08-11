#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
    int n = s.length();

if (n <= 1) {
    return s;
}

string best = "";

for (int pivot = 0; pivot < n; pivot++) {

    // =========================
    // Odd-length palindrome
    // =========================
    int first = pivot;
    int sec = pivot;

    while (first >= 0 && sec < n && s[first] == s[sec]) {
        int len = sec - first + 1;

        if (len > best.length()) {
            best = s.substr(first, len);
        }

        first--;
        sec++;
    }

    // =========================
    // Even-length palindrome
    // =========================
    first = pivot;
    sec = pivot + 1;

    while (first >= 0 && sec < n && s[first] == s[sec]) {
        int len = sec - first + 1;

        if (len > best.length()) {
            best = s.substr(first, len);
        }

        first--;
        sec++;
    }
}

return best;
    }
};