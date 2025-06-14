class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();
        int left = 0, right = n - k;
        
        // Binary search for the leftmost index of the window of size k
        while (left < right) {
            int mid = left + (right - left) / 2;
            // Compare distances from x
            if (x - arr[mid] > arr[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        
        // Return the subarray
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
        // int n=arr.size();
        // vector<int>idx(n);
        // int mn_ele=INT_MAX,mn_idx=-1;
        // for(int i=0; i<n; ++i){
        //     idx[i]=abs(arr[i]-x);
        //     if(idx[i]<mn_ele){
        //         mn_ele=idx[i];
        //         mn_idx=i;
        //     }
        // }
        // int cnt=1,i=mn_idx,j=mn_idx,start=mn_idx,end=mn_idx;
        // while(i>=0 && j<n && cnt<=k){
        //     if(cnt==k){
        //         start=i;
        //         end=j;
        //         break;
        //     }
        //     cnt+=2;
        //     i--;
        //     j=n-i+1;
        // }

        // if(cnt<k){
        //     if(i==0){
        //         start=i;end=j+k-cnt;
        //     }
        //     else if(j==n-1){
        //       start=i-(k-cnt);end=j;
        //     }
        // }
        // vector<int>ans;
        // for(int i=start; i<=end; ++i){
        //     ans.push_back(arr[i]);
        // }

        // return ans;
        
    }
};