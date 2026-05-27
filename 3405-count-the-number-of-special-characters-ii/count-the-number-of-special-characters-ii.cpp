class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        vector<int>vs(26,0),vc(26,0);
        for(int i=0; i<n; i++){
            if(word[i]>='a' && word[i]<='z') vs[word[i]-'a']=i+1;
            else if(!vc[word[i]-'A']) vc[word[i]-'A']=i+1;
        }
        int ans=0;
        for(int i=0; i<26; i++){
            if(vs[i] && (vs[i]<vc[i]))ans++;
        }

        return ans;
    }
};