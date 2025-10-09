class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        if (n == 0 || m == 0) return 0;

         
        vector<long long> prevFinish(n, 0);

        for (int j = 0; j < m; ++j) {
           
            vector<long long> pref(n);
            pref[0] = 1LL * skill[0] * mana[j];
            for (int i = 1; i < n; ++i) {
                pref[i] = pref[i-1] + 1LL * skill[i] * mana[j];
            }

             
            long long S = prevFinish[0];  
            for (int i = 1; i < n; ++i) {
                
                long long need = prevFinish[i] - pref[i-1];
                if (need > S) S = need;
            }
            if (S < 0) S = 0;  
            for (int i = 0; i < n; ++i) {
                prevFinish[i] = S + pref[i];
            }
        }

        return prevFinish[n-1];  
    }
};