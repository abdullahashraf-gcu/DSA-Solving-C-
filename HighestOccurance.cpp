#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


int main(){
vector<int>numss ={5,5,5,1,1,1};
int n = numss.size();
//hashing here 
unordered_map<int,int> hash;
for(int i =0 ; i<n ;i++){
    hash[numss[i]]++;
};
    int maxKey = hash.begin()->first;
    int maxValue = hash.begin()->second;

    for (const auto& pair : hash) {
        if (pair.second > maxValue || pair.second == maxValue && pair.first < maxKey) {
            maxValue = pair.second;
            maxKey = pair.first;
        } 
    }


cout<<" Most occuring :"<< maxKey;


}