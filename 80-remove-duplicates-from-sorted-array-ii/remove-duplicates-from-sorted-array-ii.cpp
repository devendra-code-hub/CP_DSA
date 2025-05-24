class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i = 0;  
        for (int n : nums) {
            
            if (i < 2 || n != nums[i - 2]) {
                nums[i++] = n;
            }
        }
        return i; 
        // int n=v.size();
        // unordered_map<int,int>freq;
        // for(int i=0; i<n; ++i){
        //     freq[v[i]]++;
        // }
        // vector<int>ans;
        // for(auto & it: freq){
        //     if(it.second>2){
        //         ans.push_back(it.first);
        //         ans.push_back(it.first);
        //     }
        //     else{
        //         for(int i=0; i<it.second; ++i){
        //             ans.push_back(it.first);
        //         }
        //     }
        // }
        // int k=ans.size();
        // // int a=_;
        // // for(int i=0; i<n-k; ++i){
        // //     ans.push_back(a);
        // // }

        // return k;
    }
};