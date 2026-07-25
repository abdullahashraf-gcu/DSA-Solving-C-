#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // Base case: If there are fewer than 2 days, no profit can be made
        if (prices.size() < 2) return 0;

        int minPrice = prices[0]; // Track the lowest buying price seen so far
        int maxProfit = 0;        // Track the maximum profit possible

        // Single pass O(N) loop
        for (int i = 1; i < prices.size(); i++) {
            // 1. If we find a lower price, update our minimum buying price
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } 
            // 2. Otherwise, check if selling today yields a higher profit
            else if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }

        return maxProfit;
    }
};