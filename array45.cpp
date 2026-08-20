// #include <iostream>
// #include <vector>
// #include<algorithm>
// #include<unordered_map>
// #include<unordered_set>

 // sol is correct my compiler is old so commenting to show no error in folder
// using namespace std;

// class Solution {
// public:
//     int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
//         unordered_map<int, unordered_set<int>> mp;

//         // Store reserved seats for each row
//         for (auto& seat : reservedSeats) {
//             mp[seat[0]].insert(seat[1]);
//         }

//         // Every completely empty row can accommodate 2 groups
//         int ans = 2 * n;

//         for (auto& [row, seats] : mp) {

//             bool left = true;    // 2,3,4,5
//             bool middle = true;  // 4,5,6,7
//             bool right = true;   // 6,7,8,9

//             // Check left block
//             for (int s = 2; s <= 5; s++) {
//                 if (seats.count(s)) {
//                     left = false;
//                     break;
//                 }
//             }

//             // Check middle block
//             for (int s = 4; s <= 7; s++) {
//                 if (seats.count(s)) {
//                     middle = false;
//                     break;
//                 }
//             }

//             // Check right block
//             for (int s = 6; s <= 9; s++) {
//                 if (seats.count(s)) {
//                     right = false;
//                     break;
//                 }
//             }

//             // We initially assumed this row has 2 groups.
//             if (left && right) {
//                 // Can still fit 2
//             }
//             else if (left || middle || right) {
//                 // Can fit only 1
//                 ans--;
//             }
//             else {
//                 // Can fit 0
//                 ans -= 2;
//             }
//         }

//         return ans;
//     }
// };