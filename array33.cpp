#include<iostream>
#include<string>

using namespace std;

int main(){
    string s = "()(())((()()))";
    int depth=0;
    int maxDepth=0;

    for(int i =0; i<s.length();i++){
        char c=s[i];
        if(c=='('){
            depth++;
        }
        if(depth>maxDepth){
            maxDepth=depth;
        }
        if(c==')'){
            depth--;
        }
    }

    cout<<maxDepth<<endl;

}