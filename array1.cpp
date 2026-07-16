#include<iostream>
#include<vector>
using namespace std;

int main(){



// i need to check if array is sorted 
// i will assume at base case that array is rotated 
// i will treat it as a mountain 
//i will take each element and check if it the next element is greater
//whenever the next element is not greater , from that i will start checking if the next is less

vector<int> nums={3,4,5,1,2,};
int index=0;
bool is_sorted=true;

while(index<nums.size() && nums[index]<=nums[(index+1)%nums.size()]){
 
index++;

}

if(index>nums.size() ){
    is_sorted=false;
}



while(is_sorted&& index<nums.size()-1){
    
  
    index++;

      if(nums[index]>nums[(index+1)%nums.size()]){
        cout<<index<<endl;
        is_sorted=false;
        break;
    }

}

cout<<(is_sorted?"Array is Sorted":"Array is not sorted")<<endl;
    return 0;
}

// int count = 0; Most Optimal Solution

// for(int i = 0; i < nums.size(); i++) {
//     if(nums[i] > nums[(i+1) % nums.size()])
//         count++;
// }

// return count <= 1;