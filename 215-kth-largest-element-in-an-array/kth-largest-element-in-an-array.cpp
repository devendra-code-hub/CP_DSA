class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int>pq(nums.begin(),nums.end());
        int cnt=1,ans=0;
        while(!pq.empty()){
            if(k==cnt){
                ans=pq.top();
            }
            pq.pop();
            cnt++;
        }

        return ans;
    }
};