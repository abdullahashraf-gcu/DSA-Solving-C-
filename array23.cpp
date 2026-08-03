#include<iostream>
#include<string>

using namespace std;

int main(){
    string num="52";
    int n=num.length();
    string larg="";
   
    while(n>0){
        if (!(num[--n]%2==0)){
           
            larg=num.substr(0,n+1);
            break;
        }
    }
    cout<<larg<<endl;
}