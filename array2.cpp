#include<iostream>
#include<vector>
using namespace std;

int main (){
    vector<int> nums={1,1,1,2,3,3,3,6,8,8};
    int uniqueIndex=0;
    for (int i =1; i<nums.size();i++){
        if(nums[uniqueIndex]==nums[i]){
            continue;
        }
        nums[++uniqueIndex]=nums[i];
    }

    for(int i =0;i<nums.size();i++){
        cout<<nums[i]<<endl;
    }
}