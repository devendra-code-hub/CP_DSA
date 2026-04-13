class Solution {
     public:
     using ll = long long;
     vector<int> findNGE(vector<int>&v){
        int n= v.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && v[i]>=v[st.top()] ) st.pop();
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
     }
     vector<int> findPGEE(vector<int>&v){
        int n= v.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && v[i]>v[st.top()] ) st.pop();
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
     }
     vector<int> findNSE(vector<int>&v){
        int n= v.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && v[i]<=v[st.top()] ) st.pop();
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
     }
     vector<int> findPSEE(vector<int>&v){
        int n= v.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && v[i]<v[st.top()] ) st.pop();
            ans[i] = !st.empty() ?  st.top() : -1;
            st.push(i);
        }
        return ans;
     }
     ll  sumOfMax(vector<int>& v){
        int n=v.size();
        vector<int>nge = findNGE(v);
        vector<int>pge = findPGEE(v);
        ll sum=0;
        for(int i=0; i<n; i++){
            ll left = i-pge[i];
            ll right =nge[i]-i;
            ll val = left*v[i]*right*1LL;
            sum+=val;
        }
        return sum;
      }
      ll  sumOfMin(vector<int>& v){
        int n=v.size();
        vector<int>nse = findNSE(v);
        vector<int>pse = findPSEE(v);
        ll sum=0;
        for(int i=0; i<n; i++){
            ll left = i-pse[i];
            ll right =nse[i]-i;
            ll val = left*v[i]*right*1LL;
            sum+=val;
        }
        return sum;
      }
  
 
    long long subArrayRanges(vector<int>& nums) {
        return sumOfMax(nums) - sumOfMin(nums);
    }
};