class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>freq;
        for(auto it : nums) freq[it]++;

        auto comp=[&freq](int n1, int n2){
            return freq[n1]>freq[n2];
        };

        priority_queue<int, vector<int>, decltype(comp)> pq(comp);

        for(auto it : freq){
            pq.push(it.first);
            if(pq.size()>k) pq.pop();
        }

        vector<int>ans(k);
        for(int i=0; i<k; i++){
            ans[i]=pq.top();
            pq.pop();
        }
 
        return ans;
    }
};