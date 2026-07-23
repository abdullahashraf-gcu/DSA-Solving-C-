#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> nums={-2,-1};
    //                0    2   1  4   2  6  0   1  6   4
    int sum =0, currentSum=-9999;
    int start=0 ,end =0 , curGreat=nums[0];

    for( int i =0 ; i<nums.size();i++){
        if ( sum==0){
            start=i;
      
        }
        sum+=nums[i];
        if(sum>currentSum){
            currentSum=sum;
            cout<<i<<" "<<currentSum<<endl;
            end=i;
        }
        if(sum<0){
            sum=0;
        }
        if (nums[i]>curGreat){
            curGreat=nums[i];
        }
    }

    if(currentSum<0){
        currentSum=curGreat;
        cout<<curGreat<<endl;
    }
    
    cout<<start<<" "<<end<<" "<<currentSum<<endl;
    cout<<(-2>-1)<<endl;
}

//optimal solution :
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // Choice: add to current sum OR start fresh at nums[i]
            if (currentSum < 0) {
                currentSum = nums[i]; // Start fresh
            } else {
                currentSum += nums[i]; // Extend current sum
            }

            // Update maximum sum found so far
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }

        return maxSum;
    }
};