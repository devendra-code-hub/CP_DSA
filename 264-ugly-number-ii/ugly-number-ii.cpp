class Solution {
public:
    int nthUglyNumber(int n) {
         // multiple of 2,3,5
         priority_queue<long, vector<long>, greater<long>> mnheap;
         set<long>seenNum;

         vector<int>primef={2,3,5};
         mnheap.push(1);
         seenNum.insert(1);
         long curugly=1;
         for(int i=0; i<n; ++i){
            curugly=mnheap.top();
            mnheap.pop();
            for(int p: primef){
             long   nextugly=p*curugly;
                if(seenNum.find(nextugly) == seenNum.end()){
                    mnheap.push(nextugly);
                    seenNum.insert(nextugly);
                }
            }
         }

         return static_cast<int>(curugly);
    }
};