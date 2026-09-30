class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>ans;
        int d=0;
        for(auto c: seq){
            if( c=='('){
                d++;
                if(d%2==0){
                    ans.push_back(0);
                }else ans.push_back(1);
            }else{
                if(d%2 ==0)ans.push_back(0);
                else ans.push_back(1);
                d--;
            }
        }
        return ans;
    }
};