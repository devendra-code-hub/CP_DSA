class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(), ans=0, l=0, mxf=0;
        unordered_map<char,int>mp;
        for(int r=0; r<n; r++){
            mp[s[r]]++;
            mxf=max(mxf,mp[s[r]]);
            while(l<=r && (r-l+1-mxf)>k){
                mp[s[l]]--; 
                l++;
            }

            ans=max(ans, r-l+1);
             
        }

        return ans;
    }
};