#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    static constexpr int MOD = 1e9 + 7;

    struct Node {
        long long count_total = 0;
        long long sq_total = 0;
        long long lazy = 0;
    };

    int n;
    vector<Node> tree;

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0) return;
        long long lazy_val = tree[node].lazy;
        int mid = l + (r - l) / 2;

        apply(2 * node, l, mid, lazy_val);
        apply(2 * node + 1, mid + 1, r, lazy_val);

        tree[node].lazy = 0;
    }

    void apply(int node, int l, int r, long long lazy_val) {
        long long len = r - l + 1;
        // new_sq_total = sum((c + lazy)^2) = sum(c^2) + 2*lazy*sum(c) + len * lazy^2
        tree[node].sq_total = (tree[node].sq_total + 
                               2 * lazy_val * tree[node].count_total + 
                               len * lazy_val % MOD * lazy_val) % MOD;
        // new_count_total = sum(c + lazy) = sum(c) + len * lazy
        tree[node].count_total = (tree[node].count_total + len * lazy_val) % MOD;
        tree[node].lazy = (tree[node].lazy + lazy_val) % MOD;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }
        push(node, l, r);
        int mid = l + (r - l) / 2;
        update(2 * node, l, mid, ql, qr);
        update(2 * node + 1, mid + 1, r, ql, qr);
        
        tree[node].count_total = (tree[2 * node].count_total + tree[2 * node + 1].count_total) % MOD;
        tree[node].sq_total = (tree[2 * node].sq_total + tree[2 * node + 1].sq_total) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node());
        unordered_map<int, int> last_seen;
        long long ans = 0;

        for (int r = 0; r < n; ++r) {
            int lasti = last_seen.count(nums[r]) ? last_seen[nums[r]] : -1;
            // Update range [lasti + 1, r] by adding 1 to distinct counts
            update(1, 0, n - 1, lasti + 1, r);
            last_seen[nums[r]] = r;

            // The root of the segment tree now holds the sum of squares for all subarrays ending at r
            ans = (ans + tree[1].sq_total) % MOD;
        }

        return ans;
    }
};
// class Solution {
// public:
//     int sumCounts(vector<int>& nums) {
//         int n=nums.size();
//         int mod=1e9+7;
//         int ans=0;
//         set<int>s;
//         vector<int>d;
//         for(auto it : nums){
//             s.insert(it);
//             d.push_back(s.size());
//         }
//         for(int i=0; i<n; i++){
//             int num=(d[i]*d[i])%(mod);
//             int num2= (num*(n-i))%mod;
//             ans=(ans+num2)%mod;
//         }

//         return ans;
//     }
// };