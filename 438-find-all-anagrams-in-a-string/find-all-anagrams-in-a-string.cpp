class Solution {
public:
bool check(vector<int>&v1, vector<int>&v2){
    return v1==v2;
}
    vector<int> findAnagrams(string s, string p) {
         int k=p.size();
        vector<int>v1(26,0), v2(26,0), ans;
        for(auto c: p)v1[c-'a']++;
        int l=0;
        for(int r=0; r<s.size(); r++){
            v2[s[r]-'a']++;
            while(l<=r && r-l+1>k){
                v2[s[l]-'a']--;
                l++;
            }
            if(check(v1,v2))ans.push_back(l);
        }

        // return false;
        return ans;
    }
};