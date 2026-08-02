#include <iostream>
#include <string>
#include<vector>
#include <algorithm>

using namespace std;

int main() {
    string str = "aabbbbaa"; 


    int n = str.length();
    int halfLen = n / 2; 
    string part1 = str.substr(0, halfLen);
    char pivotChar = '\0';
    bool hasPivot = false;

    if (n % 2 != 0) {
        pivotChar = str[halfLen]; 
        hasPivot = true;
    }
    sort(part1.begin(), part1.end());


    int minGreat = 256;
    int mingIndex = -1;
    int sortIndex = 0;
    int k = 6;  
    int cur = 1; 

    cout << "Permutation 1: " << part1 << endl;

    // part1 length is halfLen (3). The last valid index is halfLen - 1 (2).
    // We scan i from halfLen - 1 down to 1 so that part1[i] and part1[i-1] are valid!
    for (int i = halfLen - 1; i > 0; i--) {
        if (cur == k) {
            break;
        }

        // Check if current adjacent pair is increasing
        if (part1[i] > part1[i - 1]) {
            
            // Search for smallest character greater than part1[i-1] within valid bounds [i, halfLen - 1]
            for (int j = i; j < halfLen; j++) {
                if (part1[j] > part1[i - 1] && part1[j] < minGreat) {
                    minGreat = part1[j];
                    mingIndex = j;
                }
            }

            // Swap pivot with the next smallest larger character
            part1[mingIndex] = part1[i - 1];
            part1[i - 1] = minGreat;
            
            // Sort everything after index i-1 to get the next smallest order
            sortIndex = i;
            sort(part1.begin() + sortIndex, part1.end()); // Or part1.begin() + halfLen

            cur++;
            cout << "Permutation " << cur << ": " << part1 << endl;

            // Reset variables for next pass
            minGreat = 256;
            mingIndex = -1;

            // Reset loop index i to start searching from the rightmost character again
            i = halfLen; // After i-- in loop header, i becomes halfLen - 1
        }
    }
string result ;
if (k==cur){
  
    std::string part2(part1.rbegin(), part1.rend());


   result = part1 + (hasPivot ? string(1, pivotChar) : "") + part2 ;
}else {
  result = "";
}

cout<< result<<endl;
    return 0;
}

// the above solution is correct but not optimal , optimal sol : 
class Solution {
public:
    static constexpr int MAX = 1000001;

    int comb(int n, int k) {
        if (k > n) return 0;
        k = min(k, n - k);
        long long res = 1;
        for (int i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;
            if (res >= MAX) return MAX;
        }
        return (int)res;
    }

    int countWays(vector<int>& cnt) {
        int rem = 0;
        for (int x : cnt) rem += x;

        long long res = 1;
        for (int x : cnt) {
            if (x == 0) continue;
            res *= comb(rem, x);
            if (res >= MAX) return MAX;
            rem -= x;
        }
        return (int)res;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> halfCnt(26);
        string mid = "";

        int halfLen = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1)
                mid.push_back(char('a' + i));

            halfCnt[i] = freq[i] / 2;
            halfLen += halfCnt[i];
        }

        if (countWays(halfCnt) < k)
            return "";

        string left;

        for (int pos = 0; pos < halfLen; pos++) {

            for (int c = 0; c < 26; c++) {

                if (halfCnt[c] == 0)
                    continue;

                halfCnt[c]--;

                int ways = countWays(halfCnt);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                halfCnt[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};