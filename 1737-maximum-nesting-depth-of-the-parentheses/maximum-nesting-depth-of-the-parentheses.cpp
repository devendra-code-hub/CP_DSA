class Solution {
public:
    int maxDepth(string s) {
        int cnt=0,ans=0;
        for(auto c : s){
            if(c=='(') {cnt++;ans=max(ans,cnt);}
            else if(c==')') cnt--;
        }

        return ans;
        
    }
};