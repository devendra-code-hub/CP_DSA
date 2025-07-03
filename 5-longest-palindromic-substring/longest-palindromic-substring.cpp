class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(),start=0,mxlen=0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<=1; j++){
                int low = i;
                int high = i+j;
                while(low>=0 && high<n && s[low] == s[high]){
                int currlen = high-low+1;
                if(currlen>mxlen){
                    start=low;
                    mxlen=currlen;
                }
                low--;
                high++;
                }
            }
        }

        return s.substr(start,mxlen);
    }
};