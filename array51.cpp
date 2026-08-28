#include <iostream>
#include <string>
#include<algorithm>


using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        int ones = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            if (s[r] == '1') {
                ones++;
            }

            // Shrink from the left if we have more than k ones
            // or if the left character is '0' and we already have k ones
            while (ones > k || (l < r && s[l] == '0')) {
                if (s[l] == '1') {
                    ones--;
                }
                l++;
            }

            // Check if current window has exactly k ones
            if (ones == k) {
                string sub = s.substr(l, r - l + 1);
                
                if (ans.empty() || sub.length() < ans.length() || 
                   (sub.length() == ans.length() && sub < ans)) {
                    ans = sub;
                }
            }
        }

        return ans;
    }
};