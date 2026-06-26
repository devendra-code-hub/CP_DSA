#include <vector>

using namespace std;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Array to store frequencies of each prefix sum.
        // Size is 2*n + 1 to handle prefix sums from -n to +n.
        vector<int> pref_counts(2 * n + 1, 0);
        
        int offset = n;         // Shift to avoid negative array indices
        int current_pref = offset; 
        
        pref_counts[current_pref] = 1; // Base case: prefix sum of 0 (offset) before starting
        
        long long ans = 0;
        long long smaller_count = 0; // Tracks how many previous prefix sums are strictly < current_pref
        
        for (int num : nums) {
            if (num == target) {
                // Moving right (+1). We gain all the previous prefix sums that are equal to our old current_pref.
                smaller_count += pref_counts[current_pref];
                current_pref++;
            } else {
                // Moving left (-1). We lose all previous prefix sums that are equal to our new current_pref.
                current_pref--;
                smaller_count -= pref_counts[current_pref];
            }
            
            // Add the number of valid subarrays ending at this element
            ans += smaller_count;
            
            // Record this new prefix sum for future iterations
            pref_counts[current_pref]++;
        }
        
        return ans;
    }
};