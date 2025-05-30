class Solution {
public:
vector<string>numberPad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string>ans;

void backtrack(int idx, string&digits, string current){
    int n=digits.size();
    if(idx>=n){
        ans.push_back(current);
        return;
    }

    for(auto& letter: numberPad[digits[idx]-'0']){
        backtrack(idx+1,digits,current+letter);
    }
}
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty()) return {};

        backtrack(0,digits,"");

        return ans;
        
    }
};