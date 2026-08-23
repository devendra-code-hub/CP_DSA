class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string s1=strs[0], s2=strs[strs.size()-1];
        int l=0,r=0;
        while(l<s1.size() && r<s2.size() && s1[l]==s2[r]){
            l++;
            r++;
        }
        
        return s1.substr(0,l);
        
            }
};