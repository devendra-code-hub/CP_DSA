class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        for(int i=0; i<n1; i++){
            int ch=nums1[i];
            int l=0,r=n2-1;
            while(l<=r){
                int m=(l+r)/2;
                if(nums2[m]==ch) return ch;
                else if(ch<nums2[m]) r=m-1;
                else l=m+1;
            }
        }

        return -1;
    }
};