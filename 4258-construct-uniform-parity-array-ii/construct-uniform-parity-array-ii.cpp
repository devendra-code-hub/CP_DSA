class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());
        int cnt_e=0;
        int n =nums1.size();
        for(int i=0; i<n; i++) {
            if(nums1[i]%2 ==0) cnt_e++;
        }
        if(mn %2 == 0 && cnt_e != n) return false;

        return true;
    }
};