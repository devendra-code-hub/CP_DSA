class Solution {
public:
    map<int,int> dp[10001][2];
    int func(string& s,int k,int ind,int curset,int allowed){
        if(ind>=s.size()) return 1;

        if(dp[ind][allowed].count(curset)) return dp[ind][allowed][curset];
        int code = s[ind] - 'a'; // a->0 , b-> 1 ...   (1<<code)
        int updatedset = curset | (1<<code);
        int cnt = __builtin_popcount(updatedset) ; // no. of set bits on including current char
        int res;
        if(cnt>k){
            res = 1 + func(s,k,ind+1,(1<<code),allowed);
        }
        else{
            res = func(s,k,ind+1,updatedset,allowed);
        }

        if(allowed){
            for(int i=0;i<26;i++){
                if(i==code) continue;
                int newset = curset | (1<<i); // i am replacing code (cur char ind) by i
                int newcnt = __builtin_popcount(newset);

                if(newcnt>k){
                    res = max(res, 1 + func(s,k,ind+1,1<<i,false));
                }
                else{
                    res = max(res, func(s,k,ind+1,newset,false));
                }
            }
        }
        dp[ind][allowed][curset] = res;
        return res;
    }
    int maxPartitionsAfterOperations(string s, int k) {
        // ind, curset, allowed
        return func(s,k,0,0,1);
    }
};