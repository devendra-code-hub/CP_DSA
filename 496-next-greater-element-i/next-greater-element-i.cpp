class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
         unordered_map<int,int>mp;
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            
            while(!st.empty() && st.top()< nums2[i]) st.pop();
            if(!st.empty()) mp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        vector<int>ans(nums1.size(), -1);
        int k=0;
        for(auto num: nums1){
            if(mp.find(num) != mp.end()) { ans[k]=mp[num]; }
            k++;

        }
        
        return ans;
        
    }
};