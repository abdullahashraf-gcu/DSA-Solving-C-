#include<iostream>
#include<string>

using namespace std;

int main(){
    string s = "aba";
    int n =s.length();
    bool breac=false;

    int pivot=n/2;
    int first=0,sec=0;

    if(n%2==0){
        sec=pivot;
        first=pivot-1;
        cout<<first<<sec<<endl;
    }else{
        sec=pivot+1;
        first=pivot-1;
        cout<<first<<sec<<endl;
    }
  while(true){
        char f=s[first];
        char se=s[sec];
        if(f!=se || (first==0&&sec==n-1)){
            if(f!=se){
                breac=true;
            }
            break;
        }
        first--;
        sec++;
    }
  
    int startIdx, len;
    
    if (breac) {
      
        // We must step back inward by 1.
        startIdx = first + 1;
        len = (sec - 1) - startIdx + 1; // Formula for length: end - start + 1
    } else {
       
        startIdx = first;
        len = sec - startIdx + 1;
    }

    string t = s.substr(startIdx, len);
    cout << "Longest Center Palindrome: " << t << endl;

}