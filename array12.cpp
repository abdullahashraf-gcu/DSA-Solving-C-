#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> nums={3,1,-2,-5,2,-4};
    int n = nums.size();
    int index=0;
   
    vector<int> pos;
    vector<int> neg;

    for( int i =0 ; i<nums.size();i++){
        if (nums[i]<0){
            neg.push_back(nums[i]);
        }else{
            pos.push_back(nums[i]);
        }
    }
    int posi=0;
    int negi=0;
    for( int i =0 ; i<nums.size();i++){
     if(i%2==0){
        nums[i]=pos[posi++];
     }else{
        nums[i]=neg[negi++];
     }
    }

    for(int i =0 ; i <nums.size();i++){
        cout<<nums[i]<<" ";
    }

    
}