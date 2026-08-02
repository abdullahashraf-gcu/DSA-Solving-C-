#include<iostream>
#include<string>

using namespace std;

int main (){

    string s = "(()())(())(()(()))";
    int total=0;
    int depth=0;
    string answer="";


    
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c=='('){
            depth++;
        }else if ( c==')'){
            depth--;
        }
        
        if((depth==1 && c=='(') ||(depth==0 && c==')') ){
            continue;
        }else{
            answer+=c;
        }
       
       
    }

   cout<<answer;

}