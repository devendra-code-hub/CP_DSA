class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        vector<int>vs(26,0),vc(26,0);
        for(auto c: word){
            if(c>='a' && c<='z') vs[c-'a']=1;
            else vc[c-'A']=1;
        }
        int ans=0;

        for(int i=0; i<26; i++) if(vs[i] && vs[i]==vc[i]) ans++;

        return ans;
    }
};