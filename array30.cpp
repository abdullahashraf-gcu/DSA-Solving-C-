#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main (){
    
   string s ="abcde", goal="cdeab";
          bool isMatch = false;
          string target=goal;

    // 2. Safety checks: Ensure lengths are equal and string is not empty
    if (s.length() > 0 && s.length() == target.length()) {
        
        int n = s.length();
        
        // 3. Loop to rotate the string n times
        for (int i = 0; i < n; i++) {
            
            // Compare the current state of 's' with 'target'
            if (s == target) {
                isMatch = true;
                cout << "\nMatch found after " << i << " shifts!" << endl;
                break; // Stop searching once a match is found
            }
            
            // 4. Rotate the string in-place
            // std::rotate takes (first, middle, last)
            // 'middle' becomes the new first element.
            // s.begin() + 1 shifts the string left by 1 (first char moves to end)
            std::rotate(s.begin(), s.begin() + 1, s.end());
            
            // Optional: Print intermediate shifts to see the process
            // cout << "Shift " << i + 1 << ": " << s << endl;
        }
        
    } else if (s == target) {
         // Edge case: Both strings are empty
         isMatch = true;
    }

    return isMatch;
    }

