class Solution {
public:
int ch(char c){
    if(c=='I') return 1;
    else if(c=='V') return 5;
    else if(c=='X') return 10;
    else if(c=='L') return 50;
    else if(c=='C') return 100;
    else if(c=='D') return 500;
    return 1000;
}
    int romanToInt(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0; i<n; i++){
            if(i+1 <n && ch(s[i]) <ch(s[i+1]))ans-=ch(s[i]);
            else ans+=ch(s[i]);
        }

        return ans;
    }
};