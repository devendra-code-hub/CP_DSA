#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to calculate the sum of digits
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Store {value, original_index}
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {nums[i], i};
        }
        
        // Sort using custom criteria: digit sum first, then value
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            int sumA = [](int x) {
                int s = 0;
                while (x) { s += x % 10; x /= 10; }
                return s;
            }(a.first);
            
            int sumB = [](int x) {
                int s = 0;
                while (x) { s += x % 10; x /= 10; }
                return s;
            }(b.first);
            
            if (sumA == sumB) return a.first < b.first;
            return sumA < sumB;
        });
        
        // Find cycles to calculate minimum swaps
        vector<bool> visited(n, false);
        int totalSwaps = 0;
        
        for (int i = 0; i < n; i++) {
            // If already visited or already in the correct position, skip
            if (visited[i] || v[i].second == i) {
                continue;
            }
            
            // Traverse the cycle
            int cycle_size = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                curr = v[curr].second; // Move to the target index
                cycle_size++;
            }
            
            // A cycle of length 'k' requires 'k - 1' swaps
            if (cycle_size > 1) {
                totalSwaps += (cycle_size - 1);
            }
        }
        
        return totalSwaps;
    }
};


// class Solution {
// public:
// static bool comp(const  pair<int,int>&a, const  pair<int,int> &b){
//     if(a.second == b.second) return a.first<b.first;

//     return a.second<b.second;
// }
//     int minSwaps(vector<int>& nums) {
//         int n=nums.size();
//         vector<pair<int,int>>v;
//         for(int i=0; i<n; i++){
//             int num=nums[i], sum=0;
//             while(num){
//                 sum+=num%10;
//                 num/=10;
//             }
//             v.push_back({nums[i], sum});
//         }
//         sort(v.begin(), v.end(), comp);

//         int ans=0;
//         for(int i=0; i<n; i++){
//             if(nums[i] != v[i].first) ans++;
//         }
//         return ans/2;
//     }
// };