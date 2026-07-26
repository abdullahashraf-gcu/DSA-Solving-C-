#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
vector<int> nums = {2,3,1,3,3};
int n =nums.size()-1;
int minGreat=101, mingIndex=-1 , sortIndex=0;
for(int i=n;i>0;i--){
    if(nums[i]>nums[i-1]){
        cout<<nums[i]<<endl;
        for(int j=i ; j<=n;j++){
                if ( nums[j]>nums[i-1]&& nums[j]<minGreat){
                    minGreat=nums[j];
                    mingIndex=j;
                }
            }
            cout<<minGreat<<endl;
            nums[mingIndex]=nums[i-1];
            cout<<nums[mingIndex]<<endl;
            nums[i-1]=minGreat;
            sortIndex=i;
            break;
    }
  
}

sort(nums.begin() + sortIndex, nums.begin() + n + 1);


 for(int i =0 ; i <nums.size();i++){
        cout<<nums[i]<<" ";
    }

}