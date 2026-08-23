class Solution {
public:
static bool comp(const pair<int,int>& a, const pair<int,int>& b ){
    return a.second>b.second;
}
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(auto it : s){
            mp[it]++;
        }
        vector<pair<char,int>>p(mp.begin(), mp.end());
        
        sort(p.begin(), p.end(), comp);
        string ans="";
        for(auto it : p){
             ans.append(it.second, it.first);
        }

        return ans;
    }
};