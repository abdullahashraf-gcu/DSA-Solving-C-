#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> nums={0,0,0,0,1,1};
    int currTally=0;
    int tally=0;
    for (int i=0; i<nums.size();i++){
            if (nums[i]==1){
                currTally++;
              currTally>tally?tally=currTally:tally=tally;
            }else if(nums[i]==0){
               currTally=0;
            }
    }
    cout<<"Max : "<<tally<<endl;

    // optimal approach : 
    class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int curr = 0;
        int ans = 0;

        for (int num : nums) {

            if (num == 1) {
                curr++;
                ans = max(ans, curr);
            }
            else {
                curr = 0;
            }

        }

        return ans;
    }
};
}