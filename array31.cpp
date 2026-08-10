#include<iostream>
#include<string>

using namespace std;

int main(){
    string s ="cacar",t="raca";
    int arr[256]={0};
    int arr1[256]={0};

    bool isAna=true;

    for(int i =0 ; i<s.length();i++){
        arr[s[i]]++;
  
    }
  
    for(int i =0 ; i<t.length();i++){
        arr1[t[i]]++;
        
    }
    for(int i =0 ; i<256;i++){
        if(arr[i]!=arr1[i]){
           
            isAna=false;
            break;
        }
    }
    cout<<isAna;
}