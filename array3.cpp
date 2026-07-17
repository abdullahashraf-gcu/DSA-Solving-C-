#include<iostream>
#include<vector>
using namespace std;
   // optimised solution : 
//    void rotate(vector<int>& nums, int k) {

//     int n = nums.size();

//     k %= n;

//     reverse(nums.begin(), nums.end());
//     reverse(nums.begin(), nums.begin() + k);
//     reverse(nums.begin() + k, nums.end());
// }
//   In Python
// def rotate(nums, k):

//     n = len(nums)
//     k %= n

//     nums.reverse()

//     nums[:k] = reversed(nums[:k])

//     nums[k:] = reversed(nums[k:])

int main(){

    int k =3;
    vector<int> nums={1,2,3,4,5,6,7};
    
    int n = nums.size();
  
    
    // Normalize k in case k is larger than the array size
    k = k % n; 


    // 1. Save the last 'k' elements into a temporary vector
    vector<int> places(k);
    for (int i = 0; i < k; i++) {
        places[i] = nums[n - k + i];
    }

    // 2. Shift the remaining elements to the right
    // Stop when i reaches k to avoid negative indexing!
    for (int i = n - 1; i >= k; i--) {
        nums[i] = nums[i - k];
    }

    // 3. Put the saved elements back at the beginning of nums
    for (int i = 0; i < k; i++) {
        nums[i] = places[i];
    }

    for(int i=0; i<nums.size()-1;i++){

        cout<<nums[i]<<" ";
    }


return 0;
}