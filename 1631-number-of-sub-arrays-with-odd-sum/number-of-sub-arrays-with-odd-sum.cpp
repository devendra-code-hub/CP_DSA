class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
         const int MOD = 1e9 + 7;
        int n = arr.size();
        long long cnt=0;
        vector<long long>prefix(n);
        prefix[0] = arr[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1]+arr[i];
        }
        int odd=0,even=0;
        for(int i=0; i<n; i++){
            if(prefix[i]%2 == 0) even++;
            if(prefix[i]%2 != 0){ odd++;
            cnt++;
            }
            if(prefix[i]%2 != 0) cnt+=even;
            else{
                cnt+=odd;
            }
            cnt%=MOD;
        }
        
        return (int)cnt;
        // for(int i=0; i<n; i++){
        //     int sum = 0;
        //     for(int j=i; j<n; j++){
        //         sum+=arr[j];
        //          if(sum%2 != 0) cnt++;
        //     }
            
        // }
        // return cnt;
    }
};