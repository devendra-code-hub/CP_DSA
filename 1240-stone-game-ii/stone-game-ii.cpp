class Solution {
public:
int f(int idx, int M, vector<int>&piles, vector<vector<int>>&dp){
    int n=piles.size();
    if(idx == n) return 0;
    if(dp[idx][M] != -1) return dp[idx][M];
    int mx=-1e9;
    int curr=0;
    for(int i=1; i<=(2*M) && i+idx-1<n; i++){
        curr+=piles[i + idx -1];
        int diff = curr-f(idx+i, max(M,i), piles, dp);
        mx=max(mx, diff);
    }

    return dp[idx][M] = mx;
}
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        int total = accumulate(piles.begin(), piles.end(),0);
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int mx_d = f(0,1,piles, dp);

        return (total+mx_d)/2;
    }
};