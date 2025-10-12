#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int MOD = 1e9 + 7;

int64 modpow(int64 a, int64 e) {
    int64 r = 1;
    while (e > 0) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

int64 modinv(int64 x) {
    return modpow((x % MOD + MOD) % MOD, MOD - 2);
}

class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();

        // Factorials for multinomial coefficients
        vector<int64> fact(m + 1, 1), invfact(m + 1, 1);
        for (int i = 1; i <= m; i++) fact[i] = fact[i - 1] * i % MOD;
        invfact[m] = modinv(fact[m]);
        for (int i = m - 1; i >= 0; i--) invfact[i] = invfact[i + 1] * (i + 1) % MOD;

        // Precompute powers: nums[i]^t
        vector<vector<int64>> pw(n, vector<int64>(m + 1, 1));
        for (int i = 0; i < n; i++) {
            for (int t = 1; t <= m; t++) {
                pw[i][t] = pw[i][t - 1] * nums[i] % MOD;
            }
        }

        // dp[used][carry][ones]
        vector<vector<vector<int64>>> dp(m + 1, vector<vector<int64>>(m + 1, vector<int64>(k + 1, 0)));
        dp[0][0][0] = 1;

        for (int idx = 0; idx < n; idx++) {
            auto ndp = vector<vector<vector<int64>>>(m + 1, vector<vector<int64>>(m + 1, vector<int64>(k + 1, 0)));

            for (int used = 0; used <= m; used++) {
                for (int carry = 0; carry <= m; carry++) {
                    for (int ones = 0; ones <= k; ones++) {
                        int64 cur = dp[used][carry][ones];
                        if (!cur) continue;

                        for (int t = 0; t + used <= m; t++) {
                            int newUsed = used + t;
                            int sum = t + carry;
                            int bit = sum & 1;
                            int newCarry = sum >> 1;
                            int newOnes = ones + bit;
                            if (newOnes > k || newCarry > m) continue;

                            int64 val = cur * pw[idx][t] % MOD * invfact[t] % MOD;
                            ndp[newUsed][newCarry][newOnes] = (ndp[newUsed][newCarry][newOnes] + val) % MOD;
                        }
                    }
                }
            }
            dp.swap(ndp);
        }

        int64 res = 0;
        for (int carry = 0; carry <= m; carry++) {
            int pop = __builtin_popcount((unsigned)carry);
            for (int ones = 0; ones <= k; ones++) {
                if (ones + pop == k) {
                    res = (res + dp[m][carry][ones]) % MOD;
                }
            }
        }

        res = res * fact[m] % MOD;  // account for all sequence orderings
        return (int)res;
    }
};
