class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> modCount;
    modCount[0] = 1;   
    
    int prefixSum = 0;
    int count = 0;

    for (int num : nums) {
        prefixSum += num;
        int mod = prefixSum % k;

         
        if (mod < 0) mod += k;

         
        if (modCount.find(mod) != modCount.end()) {
            count += modCount[mod];
        }

         
        modCount[mod]++;
    }

    return count;
    }
};