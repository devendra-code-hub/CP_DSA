class Solution {
public:
    bool isPalindrome(string& s, int i, int j){
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i, int j, int k, string &s,vector<vector<int>>&dp ){
        if(i>=s.size() || j>=s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(isPalindrome(s, i, j)){
            int take=1+ f(j+1, j+k, k, s, dp);
            int grow= f(i, j+1, k, s, dp );
            int slide= f(i+1, j+1, k, s, dp );
            return dp[i][j]=max({take, grow, slide});
        }

        int grow=f(i, j+1, k, s, dp );
        int slide=f(i+1, j+1, k, s, dp );

        return dp[i][j]=max(grow, slide);
    }
    int maxPalindromes(string s, int k) {
        int n=s.size();
        if(k==1) return n;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // vector<vector<bool>>isPalindrome(n+1);
        // for(int L=1; L<=n; L++){
        //     for(int i=0; i+L<=n; i++){
        //         int j=i-L+1;
        //         if(i==j)isPalindrome[i][j]=true;
        //         else if( i+1==j)isPalindrome[i+1][j]= s[i+1]==s[j];
        //         else{
        //             isPalindrome[i][j]=s[i]==s[j] && isPalindrome[i][j];
        //         }
        //     }
        // }

        return f(0,k-1,k,s,dp );
    }
};