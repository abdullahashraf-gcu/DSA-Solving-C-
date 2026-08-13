#include<iostream>
#include<string>

using namespace std;

int main(){
    string s = "aabcbaa";
    int n =s.length();
    bool cal=false;
    int total=0;
    for(int i=0 ; i<n-1;i++){
        int arr[26]={0};
        arr[s[i]-97]++;
        pair<char,int> min={s[i],1};
        pair<char,int> max={s[i],1};
        
       
        for(int j =i+1;j<n;j++){
            arr[s[j]-97]++;
             if(arr[s[j]-97]<=min.second ||s[j]==min.first) {
            min.second=arr[s[j]-97];
            min.first=s[j];
            cal=true;
        }
        if(s[j]==max.first || arr[s[j]-97]>=max.second){
            max.second=arr[s[j]-97];
            max.first=s[j];
            cal=true;
        }
         if(cal){
           if(max.second-min.second>0){
            total+=max.second-min.second;
           }
        }

        }
        cal=false;
    }

    cout<<total;
}

// correct Solution : 
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int total = 0;

        for (int i = 0; i < n; i++) {

            int freq[26] = {0};
            int maxFreq = 0;

            for (int j = i; j < n; j++) {

                int idx = s[j] - 'a';
                freq[idx]++;

                maxFreq = max(maxFreq, freq[idx]);

                int minFreq = INT32_MAX;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                total += maxFreq - minFreq;
            }
        }

        return total;
    }
};