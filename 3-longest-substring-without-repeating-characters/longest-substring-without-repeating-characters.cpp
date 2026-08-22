class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
         unordered_map<char,int>mp;
        int ans=0,l=0;
        for(auto r=0; r<n;  r++){
            mp[s[r]]++;
            while(l<=r && mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans, r-l+1);

        }
        return ans;
    }
};