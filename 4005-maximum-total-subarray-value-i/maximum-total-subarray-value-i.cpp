class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        using ll =long long;
        ll mx= *max_element(nums.begin(), nums.end());
        ll mn= *min_element(nums.begin(), nums.end());
        ll ans = (mx-mn)*k;
        return ans;
    }
};