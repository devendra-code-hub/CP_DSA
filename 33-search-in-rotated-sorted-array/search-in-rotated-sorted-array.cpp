class Solution {
public:
    int search(vector<int>& arr, int  k) {
       int n=arr.size();
       int l=0,r=n-1;
       while(l<=r){
        int m=(l+r)/2;
        if(arr[m]==k) return m;
        else if(arr[m]<=arr[r]){
            if(arr[m]<=k && k<=arr[r]){
                l=m+1;
            }else r=m-1;
        }
        else {
            if(k>=arr[l] && k<=arr[m]){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
       }

       return -1;
        
    }
};