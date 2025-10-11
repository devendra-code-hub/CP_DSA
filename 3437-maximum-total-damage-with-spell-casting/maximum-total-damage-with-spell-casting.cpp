class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> freq;
        for (int p : power) freq[p] += p;  

        vector<pair<int, long long>> vals(freq.begin(), freq.end());
        sort(vals.begin(), vals.end());  

        int n = vals.size();
        vector<long long> dp(n, 0);

        dp[0] = vals[0].second;   

        for (int i = 1; i < n; i++) {
           
            long long not_take = dp[i - 1];

            
            long long take = vals[i].second;
            int j = i - 1;
            while (j >= 0 && vals[i].first - vals[j].first <= 2) j--;
            if (j >= 0) take += dp[j];

            dp[i] = max(take, not_take);
        }

        return dp[n - 1];
    }
};