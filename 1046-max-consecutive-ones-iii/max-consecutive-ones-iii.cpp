class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0, maxLen = 0, zeroCount = 0;

        while (right < n) {
            
            if (nums[right] == 0) {
                zeroCount++;
            }

           
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

          
            maxLen = max(maxLen, right - left + 1);

            
            right++;
        }

        return maxLen;
    }
};
// int n = a.size();
//          int ans =0;
//         for(int i=0; i<n; i++){
//             int count=0,countz=0;
//             for(int j=i; j<n-1; j++){
//                 if(a[j] && a[j]==a[j+1]){
//                     count++;
//                 }
//                 else if(countz <= k){
//                     countz++;
//                 }
//                 else{
//                     if(countz>k) break;
//                 }
//             }
//             ans = max(ans,count+1 + countz);

//         }

//         return ans;
        