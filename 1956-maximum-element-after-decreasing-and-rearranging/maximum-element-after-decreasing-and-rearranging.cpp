class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int ans=1; bool ch=true;
        int n=arr.size();
        sort(arr.begin(), arr.end());
        for(int i=0; i<n-1; i++){
            if(arr[0] != 1) arr[0]=1;
            if(arr[i+1]-arr[i] >1){
                ch=false;
                ans=max(ans,arr[i]+1);
                arr[i+1]=arr[i]+1;
            }
        }
        if(ch) ans=arr[n-1];
        if(n==1) ans=1;

        return ans;
    }
};