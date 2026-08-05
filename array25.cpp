#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
 
    vector<int> nums = {6, 2, 9, 1, 12};

    sort(nums.begin(), nums.end());
    vector<int> missingVector;

    if (!nums.empty()) {
        
        for (int i = 0; i < nums.size() - 1; i++) {
            int var = nums[i];

          
            if (nums[i + 1] == var) {
                continue;
            }

            
            while (var + 1 < nums[i + 1]) {
                var++; 
                missingVector.push_back(var); 
            }
        }
    }

    

    return 0;
}

