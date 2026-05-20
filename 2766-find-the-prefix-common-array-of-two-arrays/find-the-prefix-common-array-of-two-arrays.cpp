class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n);
        vector<int> count(n + 1, 0);
        int common = 0;

        for (int i = 0; i < n; i++) {
            // Add A[i]
            count[A[i]]++;
            if (count[A[i]] == 2) common++;

            // Add B[i]
            count[B[i]]++;
            if (count[B[i]] == 2) common++;

            C[i] = common;
        }

        return C;
    }
};