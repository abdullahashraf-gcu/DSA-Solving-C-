#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

int main() {

    vector<int> nums = {2, 4, 1, 5, 3};
    int k = 7;
    int n = nums.size();

    int count = 0;

    // prefix[i] = sum of first i elements
    vector<int> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (prefix[j] - prefix[i] == k) {
                count++;
            }
        }
    }

    cout << count << endl;
}

//optimal 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        freq[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {

            prefixSum += num;

            if (freq.find(prefixSum - k) != freq.end())
                count += freq[prefixSum - k];

            freq[prefixSum]++;
        }

        return count;
    }
};