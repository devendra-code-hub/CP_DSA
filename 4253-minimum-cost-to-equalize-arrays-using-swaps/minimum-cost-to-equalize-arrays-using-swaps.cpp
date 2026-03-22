class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        unordered_map<int,int>mp,freq1,freq2;
        set<int>s;
        for(int i=0;i<n; i++){
            mp[nums1[i]]++;
            mp[nums2[i]]++;
            freq1[nums1[i]]++;
            freq2[nums2[i]]++;
            s.insert(nums1[i]);
            s.insert(nums2[i]);
        }
        for(auto & it : mp) if(it.second %2 != 0) return -1;
        int cost=0;

        for(auto & it  :freq1){
            if(it.second > freq2[it.first])
            cost+= (it.second-freq2[it.first])/2;
        }
        return cost;
    }
};