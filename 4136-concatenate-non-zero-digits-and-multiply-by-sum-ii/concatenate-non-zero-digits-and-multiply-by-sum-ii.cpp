class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;
        
        // 1-based prefix arrays to avoid index out of bounds on l-1
        vector<long long> p_sum(m + 1, 0);
        vector<long long> p_val(m + 1, 0);
        vector<int> nz_cnt(m + 1, 0);
        vector<long long> p10(m + 1, 1);
        
        // Precompute powers of 10 modulo 10^9+7
        for (int i = 1; i <= m; i++) {
            p10[i] = (p10[i - 1] * 10) % MOD;
        }
        
        // Build the prefix arrays in O(N)
        for (int i = 0; i < m; i++) {
            int digit = s[i] - '0';
            
            if (digit > 0) {
                p_sum[i + 1] = p_sum[i] + digit;
                nz_cnt[i + 1] = nz_cnt[i] + 1;
                p_val[i + 1] = (p_val[i] * 10 + digit) % MOD;
            } else {
                p_sum[i + 1] = p_sum[i];
                nz_cnt[i + 1] = nz_cnt[i];
                p_val[i + 1] = p_val[i];
            }
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        // Answer each query in O(1)
        for (const auto& q : queries) {
            // Shift to 1-based indexing
            int l = q[0] + 1;
            int r = q[1] + 1;
            
            long long current_sum = p_sum[r] - p_sum[l - 1];
            int current_nz = nz_cnt[r] - nz_cnt[l - 1];
            
            // Extract x using modular arithmetic
            long long subtract_val = (p_val[l - 1] * p10[current_nz]) % MOD;
            long long x = (p_val[r] - subtract_val + MOD) % MOD; // + MOD prevents negative values in C++
            
            long long res = (x * (current_sum % MOD)) % MOD;
            ans.push_back(res);
        }
        
        return ans;
    }
};