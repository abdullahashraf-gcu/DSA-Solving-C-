#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
vector<int> nums = {6,6,6,7,7};
int val =nums[0] ; int count=1 ;
int n = nums.size();


for(int i =1 ; i<nums.size(); i++){
  if (nums[i]==val){
    count++;
  }else if ( count==0){
    val=nums[i];
    count++;
  }else{
    count--;
  }
};
cout<<val;


}