class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        using ll = long long;
        unordered_map<ll,int>freq;
        for(int i=1; i<=1000; i++){
            ll a =(ll) i*i*i;
            for(int j=i; ; j++){
                ll b=(ll)j*j*j;
                ll sum = a+b;
                if(sum > n) break;
                freq[sum]++;
            }
        }
        vector<int>ans;
        for(auto & it: freq) if(it.second >=2) ans.push_back(int(it.first));
        sort(ans.begin(),ans.end());

        return ans;
    }
};