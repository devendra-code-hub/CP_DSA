class Solution {
public:
bool check(vector<int>&v1, vector<int>&v2){
    return v1==v2;
}
    bool checkInclusion(string s1, string s2) {
        int k=s1.size();
        vector<int>v1(26,0), v2(26,0);
        for(auto c: s1)v1[c-'a']++;
        int l=0;
        for(int r=0; r<s2.size(); r++){
            v2[s2[r]-'a']++;
            while(l<=r && r-l+1>k){
                v2[s2[l]-'a']--;
                l++;
            }
            if(check(v1,v2))return true;
        }

        return false;
    }
};