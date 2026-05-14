class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n =nums.size()-1;
        set<int>st;
        for(auto & it: nums) st.insert(it);
        int s=(n*(n-1)/2) +( n+n);
        int sum = accumulate(nums.begin(), nums.end(),0);
        int mx=*max_element(nums.begin(), nums.end());
        if(s==sum && st.size()==n && mx==n) return true;

        return false;
    }
};