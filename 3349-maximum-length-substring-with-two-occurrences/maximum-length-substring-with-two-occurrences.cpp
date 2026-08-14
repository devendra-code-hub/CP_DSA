class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int ans=0, l=0;
        vector<int>f(26,0);
        for(int r=0; r<n; r++){
            f[s[r] - 'a']++;
            while(l<n && f[s[r]-'a']>2){
                f[s[l]-'a']--;
                l++;
            }
            ans=max(ans, r-l+1);
        }

        return ans;
    }
};