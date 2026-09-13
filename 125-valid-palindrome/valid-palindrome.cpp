class Solution {
public:
bool check(char c){
    if((c>='a' && c<='z') || (c>='0'  && c<='9')) return true;
   return false;
}
bool palindrome(string ans){
    int l=0,r=ans.size()-1;
    while(l<=r){
        if(ans[l] != ans[r]) return false;
        l++;
        r--;
    }
    return true;
}
    bool isPalindrome(string s) {
        // s=tolower(s);
        string ans="";
        for(auto c: s){
            c=tolower(c);
            // cout<<c<<endl;
            if(check(c)){ans+=c;}
        }
        cout<<ans<<endl;
        return palindrome(ans);
    }
};