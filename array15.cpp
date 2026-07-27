#include <iostream>
#include <climits>
#include <algorithm>
#include<vector>


class Solution {
public:
    int maxProduct() {
        vector<int> nums={0,2,4,5};
        int first =0 , second=0;

        for (int i =0 ; i<nums.size();i++){
            if (nums[i]>=first){
                second=first;
                first=nums[i];
            }else if (nums[i]>second){
                second=nums[i];
            }
        }
    int num=(first-1)*(second-1);
        return num;
    }
};