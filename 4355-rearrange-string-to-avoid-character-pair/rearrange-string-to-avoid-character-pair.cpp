class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int cx=0,cy=0;
        string t;
        for(auto c: s){
            if(c==x)cx++;
            if(c==y)cy++;
        }
        while(cy){
            t+=y;
            cy--;
        }
        while(cx){
            t+=x;
            cx--;
        }
        for(auto c: s){
            if(c!=x && c!=y) t+=c;
        }

        return t;
    }
};