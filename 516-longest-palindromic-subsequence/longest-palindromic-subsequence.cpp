class Solution {
public:
    int f(int i, int j, int n, string & s, vector<vector<int>>&dp){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]=2+f(i+1,j-1,n,s,dp);
        int t=f(i+1,j,n,s,dp);
        int nt=f(i,j-1,n,s,dp);
        return dp[i][j]=max(t,nt);
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return f(0,n-1,n,s,dp);
    }
};