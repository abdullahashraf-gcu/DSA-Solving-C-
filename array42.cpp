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