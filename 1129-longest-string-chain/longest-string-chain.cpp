class Solution {
public:
 static bool comp(const string & s1, const string & s2){
    return s1.size()<s2.size();
 }
    bool check(const string & s1,const string & s2){
        if(s1.size() + 1 != s2.size()) return false;
        int l =0, r=0;
        while(r< s2.size()){
            if(l<s1.size() && s1[l]==s2[r]){
                l++;
                r++;
            }else{
                r++;
            }
        }
        return l==s1.size();
    }
    int f(int i, int p, vector<string>&s, vector<vector<int>>& dp ){
        if(i == s.size()) return 0;
        if(dp[i][p+1] !=-1) return dp[i][p+1];
        
        int len = f(i+1, p, s, dp);
        if(p==-1 || check(s[p], s[i])){
            len=max(len, 1+f(i+1, i, s, dp));
        }

        return dp[i][p+1]= len;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(), comp);
        vector<vector<int>>dp(n, vector<int>(n+1,-1));

        return f(0, -1, words, dp);
    }
};