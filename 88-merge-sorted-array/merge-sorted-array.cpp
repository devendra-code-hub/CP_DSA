class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // iterate over both the arr uptp min(m,n) , then iterate both the arr separately start_idx = min(m,n) to m , n respectively;
        vector<int> ans;
        int i = 0, j = 0;

        // Merge both arrays into ans
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                ans.push_back(nums1[i++]);
            } else {
                ans.push_back(nums2[j++]);
            }
        }

        // Add remaining elements from nums1
        while (i < m) {
            ans.push_back(nums1[i++]);
        }

        // Add remaining elements from nums2
        while (j < n) {
            ans.push_back(nums2[j++]);
        }

        // Copy back to nums1
        for (int k = 0; k < ans.size(); k++) {
            nums1[k] = ans[k];
        }
    }
};