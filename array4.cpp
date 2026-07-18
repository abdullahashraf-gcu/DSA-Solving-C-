#include<iostream>
#include<vector>
using namespace std;

int main (){

    vector<int> nums={0,12 , 0 , 0 , 1 , 2 , 3 , 0};
    int index=-1;
    for ( int i =0 ; i<nums.size();i++){
        if(nums[i]!=0){
           
            nums[++index]=nums[i];
            cout<<nums[index]<<endl;
        }
    }
    if (index==-1){}else {
    for(int i=index+1;i<nums.size();i++){
        nums[i]=0;
    }
    }
      for(int i=0; i<nums.size();i++){

        cout<<nums[i]<<" ";
    }
}