class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());
        
        // Step 1: Frequency array
        vector<int> freq(maxCost + 1, 0);
        for (int cost : costs) {
            freq[cost]++;
        }
        
        int count = 0;
        
        // Step 2: Buy from cheapest to expensive
        for (int cost = 1; cost <= maxCost; cost++) {
            if (freq[cost] == 0) continue;
            
            int canBuy = min(freq[cost], coins / cost);
            count += canBuy;
            coins -= canBuy * cost;
            
            if (coins < cost) break;
        }
        
        return count;
    }
};