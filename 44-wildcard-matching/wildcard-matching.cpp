class Solution {
public:
bool f(int i, int j, int n, int m, string& s, string& p, vector<vector<int>>&dp){
    if(i==n && j==m) return 1;
    if(j==m && i<n) return 0;
    if(i==n && j<m)  {
        for (int k = j; k < m; k++) {
                if (p[k] != '*') return 0;
            }
            return 1;
    }
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == p[j] || p[j] == '?') return dp[i][j] = f(i+1, j+1, n,m,s,p,dp);
    else if(p[j] == '*'){
        return dp[i][j] = f(i+1,j,n,m,s,p,dp) || f(i,j+1,n,m,s,p,dp);
    }else{
        return dp[i][j]=0;
    }
}
    bool isMatch(string s, string p) {
        int n=s.size(), m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return f(0,0,n,m,s,p,dp);
    }
};