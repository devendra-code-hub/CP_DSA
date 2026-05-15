class Solution {
public:
    int findMin(vector<int>& arr) {
         int n =arr.size();
         int l=0,r=n-1;
         int ans=INT_MAX;
         while(l<=r){
            int m=(l+r)/2;
            if(arr[m] <= arr[r]){
                ans=min(arr[m],ans);
                r=m-1;
            }else{
                l=m+1;
            }
         }

         return ans;
        
        
    }
};