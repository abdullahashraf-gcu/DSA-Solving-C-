#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

bool checkIsNum(char c, char n) {
    if (c == n || c == '1' || c == '2' || c == '3' ||
        c == '4' || c == '5' || c == '6' ||
        c == '7' || c == '8' || c == '9') {
        return true;
    } else {
        return false;
    }
}

int main() {
    string s = "42";
    int n = s.length();

    long long num = 0;
    int sign = 1;

    
    long long limit = 2147483647LL;

    for (int i = 0; i < n; i++) {

        char c = s[i];

        if (checkIsNum(c, '0')) {

            int digit = c - '0';

           
            if (num > limit / 10 ||
                (num == limit / 10 && digit > limit % 10)) {
                num = limit;
                break;
            }

            num = num * 10 + digit;

            int index = i + 1;

            while (index < n && checkIsNum(s[index], '0')) {

                digit = s[index] - '0';

                
                if (num > limit / 10 ||
                    (num == limit / 10 && digit > limit % 10)) {
                    num = limit;
                    break;
                }

                num = num * 10 + digit;

                index++;
            }

            break;

        } else if (c == '-' || c == '+') {

            if (c == '-') {
                sign = -1;

                
                limit = 2147483648LL;
            }

            int index = i + 1;

            while (index < n && checkIsNum(s[index], '0')) {

                int digit = s[index] - '0';

                
                if (num > limit / 10 ||
                    (num == limit / 10 && digit > limit % 10)) {
                    num = limit;
                    break;
                }

                num = num * 10 + digit;

                index++;
            }

            break;

        } else if (c == ' ') {

            continue;

        } else {

            num = 0;
            break;
        }
    }

    num *= sign;

    cout << num;

    return 0;
}