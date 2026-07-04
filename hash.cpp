#include<iostream>
#include<vector>
#include<map>
using namespace std;


int main(){
int numss[6]={5,5,5,5,5,5};
int n = 6;
//hashing here 
map<int,int> hash;
for(int i =0 ; i<n ;i++){
    hash[numss[i]]++;
};

vector<vector<int>> outputArr;
 for(auto it : hash){
            outputArr.push_back({it.first, it.second});
        }

for (int i = 0; i<outputArr.size();i++){
        cout<<"number :"<<outputArr[i][0]<<" Instances :"<< outputArr[i][1]<<endl;
}


}