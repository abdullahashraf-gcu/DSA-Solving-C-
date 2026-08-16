#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    vector<int> requests={2,0,0};
    int req= requests.size();
    int n =5;
    int curFloor=0;
    int sec=0;

    for(int i =0 ; i<req;i++){
        while(true){
            int floor=requests[i];

            if(curFloor<floor){
                sec+=floor-curFloor;
                curFloor=floor;
                break;
            }else if (curFloor>floor){
                sec+=curFloor-floor;
                curFloor=floor;
                break;
            }else if(curFloor==floor){
                break;
            }
        }
    }
    cout<<sec;

    return 0;
}