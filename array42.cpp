#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    long long k = 1000000;
    long long b = 0;
    bool inc = true;
    long long start = 0, end = 0;

    if (k <= 9) {
        cout << k << endl;
        return 0;
    }

    k -= 9;

    while (true) {
        b++;

        long long digits = to_string(b * 10).length();
        long long blockSize = digits * 10;

        if (k - blockSize < 0) {
            break;
        } else {
            k -= blockSize;
        }
    }

    if (b % 2 == 0) {
        inc = true;
        start = b * 10;
        end = start + 9;
    } else {
        inc = false;
        start = b * 10 + 9;
        end = start - 9;
    }

    string s = "";

    if (inc) {
        while (start <= end) {
            s += to_string(start);
            start++;
        }
    } else {
        while (start >= end) {
            s += to_string(start);
            start--;
        }
    }

    cout << s[k - 1] << endl;

    return 0;
}

// this code exceeds time limit , with tle code : 
class Solution {
public:
    int kthDigit(long long k) {
        long long b = 0;
        bool inc = true;
        long long start = 0, end = 0;

        

        if (k <= 9) {
            return k;
        }

        k -= 9;
        b = 1;

        long long digits = 2;

        while (true) {
            long long blocks = 9;

            for (int i = 1; i < digits - 1; i++) {
                blocks *= 10;
            }

            long long blockSize = 10 * digits;
            long long total = blocks * blockSize;

            if (k <= total) {
                break;
            }

            k -= total;
            b += blocks;
            digits++;
        }

        long long index = (k - 1) / (10 * digits);
        long long digitIndex = (k - 1) % (10 * digits);

        b += index;

        if (b % 2 == 0) {
            inc = true;
            start = b * 10;
            end = start + 9;
        } else {
            inc = false;
            start = b * 10 + 9;
            end = start - 9;
        }

        long long numberIndex = digitIndex / digits;
        long long digit = digitIndex % digits;

        long long number;

        if (inc) {
            number = start + numberIndex;
        } else {
            number = start - numberIndex;
        }

        string s = to_string(number);

        return s[digit] - '0';
    }
}; 