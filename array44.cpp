#include<iostream>
#include<string>

using namespace std;

int main(){
    string s="abc";
    class Solution {
public:
    int minOperations(string s) {
   int n =s.size();
    int total=INT16_MAX;
    for(int i=0;i<n;i++ ){
        int curOps = i;
       for(int j=0;j<n/2;j++){
        char c1= s[(i+j)%n];
        char c2= s[(i+n-1-j)%n];

        int diff1=(c1-c2+26)%26;
        int diff2=(c2-c1+26)%26;

        curOps+=min(diff1 , diff2);

           }
           total=min(curOps,total);
    }
          return total;
    }
};
}