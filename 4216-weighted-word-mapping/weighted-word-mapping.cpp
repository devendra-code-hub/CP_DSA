class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto ch: words){
            string s=ch;
            int sum=0;
            for(int i=0; i<s.size(); i++){
                sum+=weights[s[i]-'a'];
            }
            int mod=sum%26;
            ans+=('z'-mod);
        }

        return ans;
    }
};