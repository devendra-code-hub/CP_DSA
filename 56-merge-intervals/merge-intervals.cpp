class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort by start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= ans.back()[1]) {
                // Overlap → merge
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                // No overlap → push new interval
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
