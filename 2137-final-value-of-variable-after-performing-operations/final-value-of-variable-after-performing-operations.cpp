class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int n = operations.size();
        int v=0;
        for(int i=0; i<n; i++){
            if(operations[i] == "++X"|| operations[i] == "X++"){
                v+=1;
            }else if(operations[i] == "--X" || operations[i] ==  "X--"){
                v-=1;
            }
        }

        return v;
    }
};