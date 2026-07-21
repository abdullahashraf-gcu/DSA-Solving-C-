#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 1, 0, 0, 1, 0, 2, 2, 2, 0};
    int zer = 0, one = 0, two = 0;

    // Step 1: Count occurrences
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) zer++;
        else if (nums[i] == 1) one++;
        else two++;
    }

    // Step 2: Overwrite the original vector directly
    int index = 0;

    while (zer > 0) {
        nums[index++] = 0; // write 0 and advance index
        zer--;
    }
    while (one > 0) {
        nums[index++] = 1; // write 1 and advance index
        one--;
    }
    while (two > 0) {
        nums[index++] = 2; // write 2 and advance index
        two--;
    }

    // Output original array (now sorted!)
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

// optimal one pass solution ( divide it into regions )
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {

            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if (nums[mid] == 1) {
                mid++;
            }

            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};