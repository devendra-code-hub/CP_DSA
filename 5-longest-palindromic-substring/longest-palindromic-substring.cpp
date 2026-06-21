class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int len=0,stidx=-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<=1; j++){
                int l=i;
                int r=i+j;
                while(l>=0 && r<n && s[l]==s[r]){
                    if(len<r-l+1){
                        len=r-l+1;
                        stidx=l;
                    }
                    l--;
                    r++;
                }
            }
        }
        return s.substr(stidx,len);
    }
};