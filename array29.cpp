#include<iostream>
#include<map>
using namespace std;

int main(){
    string s ="badc" , t= "baba";
       int n = s.length();
    bool isISO=true;
    int arr[256];
    int arr1[256];
   for(int i =0 ; i<256;i++){
  arr[i]=-1;
  arr1[i]=-1;
   }

   for(int i =0; i <n;i++){
    char fir=s[i];
    char sec=t[i];

    if(arr[fir]==-1 && arr1[sec]==-1){
        arr[fir]=sec;
        arr1[sec]=fir;
    }else{
        if(arr[fir]==-1 || arr1[sec]==-1){
            cout<<i<<fir<<sec<<arr[fir]<<arr1[sec]<<endl;
            isISO=false;
            break;
        }
        if (arr[fir]!=sec || arr1[sec]!=fir){
            cout<<i<<fir<<sec<<arr[fir]<<arr1[sec]<<endl;
            isISO=false;
            break;

        }
    }
   }
    return isISO;

   cout<<isISO;

   


    
}