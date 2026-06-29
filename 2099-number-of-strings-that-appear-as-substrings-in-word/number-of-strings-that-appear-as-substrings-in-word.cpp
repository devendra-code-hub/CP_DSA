class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,int>mp;
        for(int i=0; i<word.size(); i++){
            for(int j=i; j<word.size(); j++){
                mp[word.substr(i,j-i+1)]++;
            }
        }
        int ans=0;
        for(auto it: patterns){
            if(mp[it]>=1)ans++;
        }
        return ans;
    }
};