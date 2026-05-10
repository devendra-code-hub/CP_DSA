#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Initialize DP array with -1 (unreachable)
        vector<int> dp(n, -1);
        
        // Base case: 0 jumps to reach the starting index
        dp[0] = 0;
        
        // Loop through each target index 'i'
        for (int i = 1; i < n; ++i) {
            // Look back at all possible starting indices 'j'
            for (int j = 0; j < i; ++j) {
                // If 'j' is reachable AND the jump is within the target condition
                if (dp[j] != -1 && abs(nums[i] - nums[j]) <= target) {
                    // Update dp[i] with the maximum jumps possible
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        // The last element contains the max jumps to reach it, or -1 if unreachable
        return dp[n - 1];
    }
};