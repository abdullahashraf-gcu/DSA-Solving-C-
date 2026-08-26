#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();

        int leftSum = 0, leftQ = 0;
        int rightSum = 0, rightQ = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                rightSum += num[i] - '0';
        }

        int sumDiff = leftSum - rightSum;
        int qDiff = rightQ - leftQ;

        if (qDiff % 2 == 0 && sumDiff == (qDiff / 2) * 9) {
            return false;
        }

        return true;
    }
};