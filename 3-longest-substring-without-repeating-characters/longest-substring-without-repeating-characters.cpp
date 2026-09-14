class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
         unordered_map<char,int>mp;
         int ans=INT_MIN,l=0;
         for(int r=0; r<s.size(); r++){
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