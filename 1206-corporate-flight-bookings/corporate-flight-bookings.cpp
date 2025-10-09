class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int  size = bookings.size();
        vector<int>ans(n+1,0);
        for(int i=0; i<size; i++){
          //  for(int j=bookings[i][0] ; j<= bookings[i][1]; j++){
            int p = bookings[i][0], q=bookings[i][1];
                ans[p-1] += bookings[i][2]; 
                ans[q] -= bookings[i][2]; 
           // }
        }
        vector<int>prefix(n,0);
        prefix[0] = ans[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + ans[i];
        }

        return prefix;
    }
};