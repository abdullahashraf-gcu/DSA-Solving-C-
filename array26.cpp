#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main(){

    vector<string>strs={"pressing","pr","press","presser","cat" };
    
sort(strs.begin(), strs.end(),
     [](const string& a, const string& b) {
         return a.length() < b.length();
     });
int length =strs[0].length();
int prefix=0;
int n = strs.size();
string checker=strs[0];

     for(int i =0 ; i<n;i++){
        int tempPref=0;
        for(int j=0;j<length;j++){
            if(checker[j]==strs[i][j]){
               
                tempPref++;
            }else{
                 cout<<strs[i]<<endl;
                cout<<strs[i][j]<<endl;
               
                break;
            }
        } 
        // cout<<prefix<<endl;
        // cout<<tempPref<<endl;
        // cout<<(prefix==0)<<(tempPref<prefix)<<(prefix==0||tempPref<prefix)<<endl;
        if(prefix==0||tempPref<prefix){
            prefix=tempPref;
            if (!prefix){
                break;
            }
        }
     }

    //  cout<<prefix;
     if(!prefix){
            checker="";
        
     }else{
         checker= checker.substr(0,prefix);
     }
     cout<<checker;

}

// i knew i did not need sorting halfway in but i was too deep to change the whole code , below is non sorting version 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string checker = strs[0];

        // Find the shortest string
        for (string &s : strs) {
            if (s.length() < checker.length())
                checker = s;
        }

        int prefix = checker.length();

        for (int i = 0; i < strs.size(); i++) {

            int temp = 0;

            while (temp < checker.length() &&
                   checker[temp] == strs[i][temp]) {
                temp++;
            }

            prefix = min(prefix, temp);

            if (prefix == 0)
                return "";
        }

        return checker.substr(0, prefix);
    }
};