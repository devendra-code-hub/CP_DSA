class Solution {
public:
    string largestOddNumber(string num) {
        int idx=-1;
        int n=num.size();
        for(int i=n-1; i>=0; i--){
            int c=num[i]-'0';
            if(c&1){
                idx=i;
                break;
            }
        }
        if(idx ==-1) return "";
        return num.substr(0,idx+1);
    }
};