class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;

        // Store all prefixes of arr1
        for (int x : arr1) {
            while (x > 0) {
                prefixes.insert(x);
                x /= 10;
            }
        }

        int ans = 0;

        // Check all prefixes of arr2 against set
        for (int y : arr2) {
            while (y > 0) {
                if (prefixes.count(y)) {
                    int len = to_string(y).size();
                    ans = max(ans, len);
                    break; // longest prefix of y found, no need to go shorter
                }
                y /= 10;
            }
        }

        return ans;
    }
};