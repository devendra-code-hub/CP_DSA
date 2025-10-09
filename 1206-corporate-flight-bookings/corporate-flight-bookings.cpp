class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int  size = bookings.size();
        vector<int>ans(n);
        for(int i=0; i<size; i++){
            for(int j=bookings[i][0] ; j<= bookings[i][1]; j++){
                ans[j-1] += bookings[i][2]; 
            }
        }

        return ans;
    }
};