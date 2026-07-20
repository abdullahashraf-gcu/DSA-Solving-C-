#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<sstream>
using namespace std;

int main() {
    vector<int> nums = {3,2,4};
    int target = 6;
    vector<int> pair = {0,0};
    map<int, string> hash;

    // Build the map
    for (int i = 0; i < nums.size(); i++) {
        if (hash.find(nums[i]) == hash.end()) {
            hash[nums[i]] = to_string(i);
        } else {
            hash[nums[i]] += "," + to_string(i);
        }
    }

    // Find the answer
    for (int i = 0; i < nums.size(); i++) {
        int miniTarget = target - nums[i];

        if (hash.find(miniTarget) != hash.end()) {

            auto it = hash.find(miniTarget);

            // Special case: same value needed twice
if (miniTarget == nums[i]) {

    string indices = it->second;

    // Only one occurrence, can't use the same element twice
    if (indices.find(',') == string::npos) {
        continue;
    }

    // More than one occurrence
    stringstream ss(indices);
    string temp;

    while (getline(ss, temp, ',')) {
        int idx = stoi(temp);

        if (idx != i) {
            pair[0] = i;
            pair[1] = idx;
            break;
        }
    }
}
else {

    pair[0] = i;

    string indices = it->second;
    stringstream ss(indices);
    string temp;
    getline(ss, temp, ',');
    pair[1] = stoi(temp);
}

break;
        }
    }

    for (int i = 0; i < pair.size(); i++) {
        cout << pair[i] << " ";
    }

    return 0;
}

// The optimal solution does the basic 2 loop solution , only optimal addition is that in second loop it checks if i=j so skip mean no self element check