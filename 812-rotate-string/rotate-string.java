class Solution {
    public boolean rotateString(String s, String goal) {
        // Step 1: Length must be same
        if (s.length() != goal.length()) return false;

        // Step 2: Check if goal is substring of s+s
        String doubled = s + s;
        return doubled.contains(goal);
    }
}