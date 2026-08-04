#include<iostream>
#include<string>
using namespace std;

int main (){
string s = "a good   example";
int n =s.length()-1;
int end=-1,start=-1;
string ans="";

for (int i =n;i>=0;i--){
    char c =s[i];
    if(end==-1 && !(c==' ')){
        end=i;
cout<<"end "<<end<<endl;
    }
    if (!(end==-1) && start==-1&& !(c==' ') && (i==0 || s[i-1]==' ')){
        start=i;
        cout<<"Start "<<start<<endl;
        while(start<=end){
            ans+=s[start++];
        }
        if(!(start==0)){
            ans+=' ';
        }
        start=end=-1;
    }
}

cout<<ans<<endl;

}