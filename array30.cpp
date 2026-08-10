#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main (){
    
   string s ="abcde", goal="cdeab";
          bool isMatch = false;
          string target=goal;

    if (s.length() > 0 && s.length() == target.length()) {
        
        int n = s.length();
       
        for (int i = 0; i < n; i++) {
            
            if (s == target) {
                isMatch = true;
                cout << "\nMatch found after " << i << " shifts!" << endl;
                break; 
            }
            
         
            std::rotate(s.begin(), s.begin() + 1, s.end());
         
        }
        
    } else if (s == target) {
       
         isMatch = true;
    }

    return isMatch;
    }

