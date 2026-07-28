#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
    string str = "dbababd";

    cout << "Original String: " << str << endl;

    int n = str.length();
    int halfLen = n / 2; 

    // First half of length 'halfLen'
    string part1 = str.substr(0, halfLen);

    // Middle/Pivot character (only if odd length)
    string pivot = (n % 2 != 0) ? string(1, str[halfLen]) : "";

    // Second half of length 'halfLen' (starts after pivot)
    string part2 = str.substr(n - halfLen);


    sort(part1.begin(), part1.end());

    //  descending order (
    sort(part2.begin(), part2.end(), greater<char>());

    // Combine: part1 + unchanged pivot + part2
    string result = part1 + pivot + part2;

    cout << "\n--- Result ---" << endl;
    cout << "Part 1 (Ascending):  " << part1 << endl;
    if (n % 2 != 0) {
        cout << "Pivot (Unchanged):   " << pivot << endl;
    }
    cout << "Part 2 (Descending): " << part2 << endl;
    cout << "Final Combined:      " << result << endl;

    return 0;
}