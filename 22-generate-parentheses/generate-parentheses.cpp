class Solution {
public:
 vector<string>res;
 void validParenthesis(int n,int open, string curr){

    if(curr.length() == 2*n){
        res.push_back(curr);
        return ;
    }

    if(open < n){
        validParenthesis(n,open+1,curr +'(');
    }

    if(curr.length()-open < open){
        validParenthesis(n,open,curr +')');
    }

 }
    vector<string> generateParenthesis(int n) {
        validParenthesis(n,0,"");

        return res;
    }
};