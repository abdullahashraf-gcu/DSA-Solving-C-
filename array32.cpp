#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s = "cacar";
    string t = "";
    int arr[256] = {0};

    
    for (int i = 0; i < s.length(); i++) {
        arr[s[i]]++;
    }

    // 2. Create a vector of pairs to store <Frequency, Character>
    // This prevents us from losing the character when we sort the frequencies!
    vector<pair<int, char>> freqVec;
    for (int i = 0; i < 256; i++) {
        if (arr[i] > 0) {
            // Push only the characters that actually appear in the string
            freqVec.push_back(make_pair(arr[i], (char)i));
        }
    }

    // 3. Sort the vector in descending order.
    // std::greater will sort based on the first element of the pair (the frequency).
    // If frequencies are tied, it sorts by the character's ASCII value descending.
    sort(freqVec.begin(), freqVec.end(), greater<pair<int, char>>());

    // 4. Iterate through the sorted frequencies and build the new string
    for (int i = 0; i < freqVec.size(); i++) {
        int currentFreq = freqVec[i].first;
        char currentChar = freqVec[i].second;

        // Push character and decrement its frequency count until it hits 0
        while (currentFreq > 0) {
            t.push_back(currentChar);
            currentFreq--;
        }
    }

    // Output results
    cout << "Original String: " << s << endl;
    cout << "Sorted by Freq:  " << t << endl;

    return 0;
}