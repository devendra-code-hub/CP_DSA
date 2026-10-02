class Solution {
public:
void f(int open, int close, string s,int n, vector<string>&ans){
    if(s.size()==2*n){
        ans.push_back(s);
        return;
    }
    if(open<n) f(open+1, close, s+'(', n, ans);
    if(close<open) f(open, close+1, s+')', n, ans);
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        f(0,0,"",n, ans);

        return ans;
    }
};