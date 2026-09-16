class Solution {
public: 
int m=1e9+7;
int dp[1001][1001];
int f(int k, int i, int n){
    if(k==0) return 1;
    if(i>=n) return 0;
    if(dp[k][i] != -1) return dp[k][i];
    int skip = f(k, i+1, n)%m;
    int take=0;
    for(int j=i+1; j<n; j++){
        take=(take + f(k-1, j, n))%m; 
    }

    return dp[k][i]= (take+ skip)%m;
}
    int numberOfSets(int n, int K) {
        memset(dp, 0, sizeof(dp));
        // return f(k,0,n)%m;
        for(int i=0; i<n; i++)dp[0][i]=1;

        for(int k=1; k<=K; k++ ){
            vector<int>preSum(n+1,0);
            for(int l=n-1; l>=0; l--){
                preSum[l]=(preSum[l+1] + dp[k-1][l])%m;
            }
            for(int i=n-1; i>=0; i--){
                int skip=dp[k][i+1]%m;
                int take=preSum[i+1];
                // for(int j=i+1; j<n; j++){
                //     take=(take+ dp[k-1][j])%m;
                // }
                dp[k][i]= (skip+take)%m;
            }
        }

        return dp[K][0];
    }
};