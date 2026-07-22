class Solution {
public:
int f(int i, int j, int n, int m, string &s , string & t, vector<vector<int>>&dp){
    if(j==m) return 1;
    if(i==n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]){
        return dp[i][j]= f(i+1, j+1, n,m, s,t,dp) + f(i+1,j,n,m,s,t,dp);
    }

    return dp[i][j] = f(i+1,j, n,m,s,t,dp);
}
    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return f(0,0,n,m,s,t,dp);
    }
};