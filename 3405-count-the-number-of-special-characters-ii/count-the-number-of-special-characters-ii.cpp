class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, INT_MAX);

        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (islower(c))
                lastLower[c - 'a'] = i;          // keep updating → gets last index
            else
                firstUpper[c - 'A'] = min(firstUpper[c - 'A'], i); // keep min → first index
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 &&
                firstUpper[i] != INT_MAX &&
                lastLower[i] < firstUpper[i])
                count++;
        }

        return count;
    }
};