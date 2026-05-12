class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort by (minimum - actual) ascending
        // Tasks with smaller buffer go last (less penalty)
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) < (b[1] - b[0]);
        });

        int ans = 0;        // minimum initial energy needed
        int consumed = 0;   // total energy consumed so far (from end)

        // Process tasks in reverse (last task first)
        // At each step, figure out minimum energy needed before this task
        for (int i = tasks.size() - 1; i >= 0; i--) {
            int actual = tasks[i][0];
            int minimum = tasks[i][1];

            consumed += actual;

            // To start this task, we need at least 'minimum' energy
            // After all subsequent tasks, we've consumed 'consumed - actual'
            // So before this task: energy >= minimum + (consumed - actual)
            ans = max(ans, minimum + consumed - actual);
        }

        return ans;
    }
};