
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // We use long long to prevent potential integer overflow during intermediate checks
        int  max2 = -1001; // Second largest number
        int  max1 = -1001; // Largest number
        int  max3 = -1001; // Third largest number

        int  min1 = 1001; // Smallest number (most negative)
        int  min2 = 1001; // Second smallest number

        for (int num : nums) {
            // Update the top 3 largest elements
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max3 = max2;
                max2 = num;
            } else if (num > max3) {
                max3 = num;
            }

            // Update the top 2 smallest elements
            if (num < min1) {
                min2 = min1;
                min1 = num;
            } else if (num < min2) {
                min2 = num;
            }
        }

        // Option A: Product of three largest numbers (e.g., all positive or all negative)
        int optionA = max1 * max2 * max3;

        // Option B: Product of two smallest (most negative) numbers and the single largest positive number
        int optionB = max1 * min1 * min2;

        return max(optionA, optionB);
    }
};

int main() {
    Solution sol;

    // Example test case containing negative numbers
    vector<int> nums = {-10, -10, 1, 3, 2, 4};

    int result = sol.maximumProduct(nums);
    cout << "Maximum Product of Three Numbers: " << result << endl;

    return 0;
}