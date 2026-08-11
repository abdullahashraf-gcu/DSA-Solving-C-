#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main(){
    string s ="III";
    int n =s.length()-1;
    unordered_map<char,int>roman={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{
        'M',1000}};
        int total=roman[s[n]];
       
        for(int i =n-1;i>=0;i--){
            if(roman[s[i]]<roman[s[i+1]]){
               
                total-=roman[s[i]];
               
            }else{
                 
                 total+=roman[s[i]];
                   

            }
        }

        cout<<total<<endl;
}