#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){

vector<int> nums={2,7,5,9};
int target=11;
unordered_map<int,int>map;

for(int i=0;i<nums.size();i++){
    map[nums[i]] = i;
}
int index1,index2;
for(int i=0;i<nums.size();i++){
    int req=target-nums[i];
   if (map.find(req) != map.end()) {
    auto it = map.find(req);
   index1=it->second;
   index2=i;
   if(index1==i){
    continue;
   }
   break;
}

}
vector<int>in={index1,index2};

}