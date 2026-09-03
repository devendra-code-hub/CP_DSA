class Solution {
public:
int Atmost(vector<int>&a, int k){
    int n=a.size(), l=0,ans=0,cnt=0;
    for(int r=0; r<n; r++){
        if(a[r]&1) cnt++;
        while(l<=r && cnt>k){
            if(a[l]&1)cnt--;
            l++;
        }
        ans+=r-l+1;
    }

    return ans;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return Atmost(nums,k)-Atmost(nums,k-1);
    }
};