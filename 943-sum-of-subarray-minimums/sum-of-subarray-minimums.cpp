class Solution {
public:
vector<int> NSE(vector<int>&v){
    int n=v.size();
    stack<int>st;
    vector<int>ans(n);
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && v[i]<=v[st.top()]) st.pop();
        ans[i]=st.empty()? n: st.top();
        st.push(i);
    }

    return ans;
}
vector<int> PSE(vector<int>&v){
    int n=v.size();
    stack<int>st;
    vector<int>ans(n);
    for(int i=0; i<n; i++){
        while(!st.empty() && v[i]<v[st.top()]) st.pop();
        ans[i]=st.empty()? -1: st.top();
        st.push(i);
    }

    return ans;
}
    int sumSubarrayMins(vector<int>& arr) {
       int mod = 1e9+7;
       using ll=long long;
        int n=arr.size();
        vector<int>nse=NSE(arr);
        vector<int>pse=PSE(arr);
        long long ans=0;
        for(int i=0; i<n; i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            ll freq=left*right*1LL;
           ll val=freq*arr[i]*1LL;
            ans=(ans+val)%(mod);
        }

        return (int)ans;
    }
};