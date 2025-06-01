class Solution {
public:
vector<string>res;
bool isValid(string&s){
    int n=s.size();
    if (s.empty() || s.length() > 3) {
            return false;
        }

          if (s.length() > 1 && s[0] == '0') {
            return false;
        }

int val = stoi(s);
        return val >= 0 && val <= 255;
    // if(n==1) return true; 
    // int val=stoi(s);
    // if(s[0] =='0' || val>255) return false;

    // return true;
}

void generateIP(int idx, string curr, int cnt, string&s){
    string temp="";
    if(idx>= s.size()) return;
    if(cnt==3){
    temp=s.substr(idx);
    if(temp.size()<=3 && isValid(temp)){
        res.push_back( curr+temp);
        return;
    }
}
    for(int i=idx; i<min(idx+3,(int)s.size()); ++i ){
        temp=temp+s[i];
        if(isValid(temp)){
            generateIP(i+1,curr+temp+'.',cnt+1,s);
        }
    }
}

    vector<string> restoreIpAddresses(string s) {
        generateIP(0,"",0,s);

        return res;
    }
};