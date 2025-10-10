class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n =energy.size();
         vector<int> dp = energy;
        
        for (int i = n - k - 1; i >= 0; i--) {
            dp[i] += dp[i + k];  
        }
        
        return *max_element(dp.begin(), dp.end());
        // int ans = INT_MIN;
        // for(int i=0; i<n; i++){
        //     int sum=0;
        //     for(int j=i; j<n; j+=k){
        //         sum+=energy[j];
        //     }
        //     ans = max(ans,sum);
        // }

        // return ans;

    }
};