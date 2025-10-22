#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // 1) Compute max_overlap via sweep-line on intervals [nums[i]-k, nums[i]+k]
        // Use events: +1 at L, -1 at R+1 (inclusive intervals)
        vector<pair<long long,int>> events;
        events.reserve(2*n);
        for (int x : nums) {
            long long L = (long long)x - k;
            long long R = (long long)x + k;
            events.emplace_back(L, +1);
            events.emplace_back(R + 1, -1); // R inclusive, so decrement at R+1
        }
        sort(events.begin(), events.end());
        int cur = 0;
        int max_overlap = 0;
        for (auto &ev : events) {
            cur += ev.second;
            max_overlap = max(max_overlap, cur);
        }

        int ans = 0;
        // candidate from v not in nums: best we can do is min(max_overlap, numOperations)
        ans = max(ans, min(max_overlap, numOperations));

        // 2) For each distinct value v in nums: compute eligible(v) and existing(v)
        for (int i = 0; i < n; ) {
            int v = nums[i];
            int start = i;
            while (i < n && nums[i] == v) ++i;
            int existing = i - start;

            long long Lval = (long long)v - k;
            long long Rval = (long long)v + k;
            // eligible = # nums in [Lval, Rval]
            int Lidx = int(lower_bound(nums.begin(), nums.end(), Lval) - nums.begin());
            int Ridx = int(upper_bound(nums.begin(), nums.end(), Rval) - nums.begin()) - 1;
            int eligible = (Ridx >= Lidx) ? (Ridx - Lidx + 1) : 0;

            int finalForV = min(eligible, existing + numOperations);
            ans = max(ans, finalForV);
        }

        return ans;
    }
};
