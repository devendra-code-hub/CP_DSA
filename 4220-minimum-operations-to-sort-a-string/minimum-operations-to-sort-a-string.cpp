class Solution {
public:
    int minOperations(string s) {
       int n = s.size();
        
        // Step 1: Check if already sorted
        bool isSorted = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] < s[i - 1]) {
                isSorted = false;
                break;
            }
        }
        if (isSorted) return 0;
        
        // Step 2: Impossible if length is 2 and unsorted
        if (n == 2) return -1;
        
        // Find global minimum and maximum characters
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());
        
        // Step 3: Check for 1 operation
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }
        
        // Step 4: Check for 2 operations
        // If mn or mx appears in the interior of the string s[1 ... n-2]
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }
        
        // Step 5: Worst case requires 3 operations
        return 3;
    }
};