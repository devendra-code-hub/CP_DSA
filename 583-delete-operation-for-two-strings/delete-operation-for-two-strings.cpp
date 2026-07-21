class Solution {
public:
int f(int i, int j, int n, int m, string &s1, string &s2, vector<vector<int>>&dp){
    if(i>=n || j>= m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]){
        return dp[i][j]=1+ f(i+1, j+1, n, m, s1,s2, dp);
    }
    int t= f(i+1,j, n,m, s1,s2, dp);
    int nt= f(i,j+1, n,m, s1,s2, dp);
    return dp[i][j]=max(t,nt);
}
    int minDistance(string word1, string word2) {
        int n=word1.size(), m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return n+m- 2*f(0,0,n,m,word1,word2,dp);
    }
};