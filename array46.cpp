#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums = {5, 4, 3, 8};
    vector<int> arr1, arr2;

    arr1.push_back(nums[0]);
    arr2.push_back(nums[1]);

    int ind1 = 0, ind2 = 0, mind = 2;

    while (mind < nums.size()) {
        if (arr1[ind1] > arr2[ind2]) {
            arr1.push_back(nums[mind++]);
            ind1++;
        } else {
            arr2.push_back(nums[mind++]);
            ind2++;
        }
    }

    vector<int> result;

    for (int i = 0; i < arr1.size(); i++) {
        result.push_back(arr1[i]);
    }

    for (int i = 0; i < arr2.size(); i++) {
        result.push_back(arr2[i]);
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}