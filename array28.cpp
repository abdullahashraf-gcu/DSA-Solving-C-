#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;


// Function to check if a target digit can be constructed with current hash table factors.
// If it can, it returns true and updates the hash table with remaining factors.
// If not, it restores the hash table to its original state and returns false.
bool canConstruct(int targetDigit, unordered_map<int, int>& hash) {
    // If target is 1, it requires no factors.
    if (targetDigit == 1) return true;

    // Temporary copy of hash table to safely try deductions
    unordered_map<int, int> tempHash = hash;

    // We only have primes 2, 3, 5, 7 in the hash map.
    // We factorize targetDigit into primes to see what it requires.
    int primes[] = {2, 3, 5, 7};
    int tempTarget = targetDigit;
    
    unordered_map<int, int> required;
    
    for (int p : primes) {
        while (tempTarget % p == 0) {
            required[p]++;
            tempTarget /= p;
        }
    }

    // If there's still a remainder, the digit requires factors not in {2,3,5,7}
    // (e.g. 0, though we only check 1-9 usually)
    if (tempTarget > 1) return false;

    // Check if we have enough factors in tempHash
    for (auto const& item : required) {
        int prime = item.first;
        int count = item.second;
        if (tempHash[prime] < count) {
            return false; // Not enough of this prime
        }
        tempHash[prime] -= count;
    }

    // If we reach here, we successfully constructed the digit.
    // Apply changes to the original hash table.
    hash = tempHash;
    return true;
}

int main() {
    string n = "1255";
    long long t = 12;
    
    // ==========================================
    // Phase 1: Build Hash Table (Your original code)
    // ==========================================
    int checker[4] = {7, 5, 3, 2};
    int p = 0;
    unordered_map<int, int> hash;
    hash[1] = 1; // Default 1
    
    long long tempT = t; // Store original t for later check if needed, though not strictly required
    while (true) {
        if (t % checker[p] == 0) {
            t /= checker[p];
            hash[checker[p]]++;
        } else {
            if (p == 3) {
                break;
            } else {
                p++;
            }
        }
    }

    // Optional Check: if t > 1 after division, t had prime factors > 7 (like 11, 13).
    // The prompt assumes t only contains {2,3,5,7}.
    
    cout << "Phase 1 Hash Map:" << endl;
    for (auto it : hash) {
        cout << it.first << " : " << it.second << endl;
    }
    cout << "----------------------" << endl;

    // ==========================================
    // Phase 2: Construct the number digit-by-digit
    // ==========================================
    string targetStr = n; // n is already a string
    vector<int> constructedDigits;
    
    // We might need to break early if we run out of factors before fulfilling all n digits
    bool factorsDepleted = false;

    for (size_t i = 0; i < targetStr.length(); i++) {
        int targetDigit = targetStr[i] - '0';
        
        bool digitConstructed = false;
        
        // Try to construct exactly targetDigit, then targetDigit+1 ... up to 9
        for (int tryDigit = targetDigit; tryDigit <= 9; tryDigit++) {
            if (canConstruct(tryDigit, hash)) {
                constructedDigits.push_back(tryDigit);
                digitConstructed = true;
                break; // Move to the next target digit
            }
        }

        // If we couldn't construct the exact target or anything larger,
        // it means we don't have the right factors.
        // We will just append 1s if we ran out of factors, but based on prompt, 
        // we assume a valid number can eventually be formed or we distribute later.
        if (!digitConstructed) {
             // If we can't construct anything >= target, we might just append a 1 
             // or whatever smallest constructible digit is left. 
             // To strictly satisfy "smallest possible single digit", let's try 1-9 from scratch.
             for(int tryDigit = 1; tryDigit <= 9; tryDigit++){
                 if(canConstruct(tryDigit, hash)){
                     constructedDigits.push_back(tryDigit);
                     digitConstructed = true;
                     break;
                 }
             }
             if(!digitConstructed) {
                 constructedDigits.push_back(1); // Fallback to 1 if completely empty
             }
        }
    }

    // ==========================================
    // Phase 3: Distribute Remaining Factors
    // ==========================================
    // "Start with the largest available factor. Try multiplying it with the digit 
    // immediately before the last position... "
    // Actually, let's just multiply starting from the last digit backwards, 
    // using the largest available prime factor.
    
    int primesDesc[] = {7, 5, 3, 2};
    
    for (int p : primesDesc) {
        while (hash[p] > 0) {
            bool placed = false;
            // Distribute this prime into the constructed digits, from right to left
            for (int i = constructedDigits.size() - 1; i >= 0; i--) {
                if (constructedDigits[i] * p <= 9) {
                    constructedDigits[i] *= p;
                    hash[p]--;
                    placed = true;
                    break; // Move to next available prime copy
                }
            }
            
            if (!placed) {
                // If it can't fit anywhere, we must append it as a new digit at the end 
                // to not ruin the >= n requirement (appending makes it 10x larger)
                constructedDigits.push_back(p);
                hash[p]--;
            }
        }
    }

    // ==========================================
    // Phase 4: Construct Final String
    // ==========================================
    string finalNumber = "";
    for (int d : constructedDigits) {
        finalNumber += to_string(d);
    }

    cout << "Target n: " << n << endl;
    cout << "Original t: " << tempT << endl; 
    cout << "Constructed >= n: " << finalNumber << endl;
    
    return 0;
}