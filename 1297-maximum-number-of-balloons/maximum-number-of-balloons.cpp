class Solution {
public:
    int maxNumberOfBalloons(string text) {
       vector<int>v(26,0);
       for(auto c: text) v[c-'a']++;
       int ans=INT_MAX;
       string s= "balloon";  
        ans=min({ans,v['b'-'a'],v['a'-'a'],v['l'-'a']/2,v['o'-'a']/2,v['n'-'a']});

        return ans;
    }
};