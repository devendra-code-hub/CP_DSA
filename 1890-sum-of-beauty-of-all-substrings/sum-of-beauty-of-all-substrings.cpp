class Solution {
public:
    int beautySum(string s) {
        int n=s.size(), ans=0;
        for(int i=0; i<n; i++){
            vector<int>f(26,0);
            for(int j=i; j<n; j++){
                f[s[j]-'a']++;
                int mx=INT_MIN,mn=INT_MAX;
                for(int k=0; k<26; k++){
                    if(f[k]){
                        mx=max(mx,f[k]);
                        mn=min(mn,f[k]);
                    }
                }
                ans+=mx-mn;
            }
        }

        return ans;
    }
};