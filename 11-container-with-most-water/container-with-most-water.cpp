class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int mxw=0;
        while(l<r){
            int h = min(height[l], height[r]);
             int width = r - l;
            mxw = max(mxw, h * width);
            
            if (height[l] < height[r])
                l++;
            else
                r--;
        }

        return mxw;
    }
};