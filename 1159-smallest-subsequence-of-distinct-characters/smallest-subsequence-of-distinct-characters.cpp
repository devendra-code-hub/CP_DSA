class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        vector<int>lo(26,-1);
        for(int i=0; i<n; i++){
            lo[s[i]-'a']=i;
        }
        vector<bool>ch(26,0);
        string res="";
        for(int i=0; i<n; i++){
            if(ch[s[i]-'a']) continue;
            while(!res.empty() && s[i]<res.back() && lo[res.back()-'a'] > i){
                ch[res.back()-'a']=0;
                res.pop_back();
            }
            res.push_back(s[i]);
            ch[s[i]-'a']=1;
        }

        return res;
    }
};