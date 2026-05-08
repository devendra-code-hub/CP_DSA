#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        // Find the maximum value to size our Sieve
        int max_val = 0;
        for (int num : nums) {
            max_val = max(max_val, num);
        }

        // 1. Sieve for Smallest Prime Factor (SPF)
        vector<int> spf(max_val + 1);
        for (int i = 2; i <= max_val; ++i) spf[i] = i;
        for (int i = 2; i * i <= max_val; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j <= max_val; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }

        // 2. Identify "active" primes (primes that can trigger a teleport)
        vector<bool> is_active_prime(max_val + 1, false);
        for (int num : nums) {
            if (num >= 2 && spf[num] == num) {
                is_active_prime[num] = true;
            }
        }

        // 3. Map active primes to the indices where nums[i] is a multiple
        vector<vector<int>> prime_to_indices(max_val + 1);
        for (int i = 0; i < n; ++i) {
            int temp = nums[i];
            while (temp > 1) {
                int p = spf[temp];
                if (is_active_prime[p]) {
                    // Avoid pushing the same index multiple times for repeated prime factors (e.g., 12 = 2*2*3)
                    if (prime_to_indices[p].empty() || prime_to_indices[p].back() != i) {
                        prime_to_indices[p].push_back(i);
                    }
                }
                // Strip out all instances of this prime factor
                while (temp % p == 0) temp /= p;
            }
        }

        // 4. Breadth-First Search (BFS)
        queue<int> q;
        vector<bool> visited_idx(n, false);
        vector<bool> used_prime(max_val + 1, false);

        q.push(0);
        visited_idx[0] = true;
        int jumps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();

                // Goal reached
                if (curr == n - 1) return jumps;

                // Move Forward
                if (curr + 1 < n && !visited_idx[curr + 1]) {
                    visited_idx[curr + 1] = true;
                    q.push(curr + 1);
                }
                // Move Backward
                if (curr - 1 >= 0 && !visited_idx[curr - 1]) {
                    visited_idx[curr - 1] = true;
                    q.push(curr - 1);
                }

                // Prime Teleportation
                int val = nums[curr];
                if (val >= 2 && spf[val] == val) { // If the current number is itself a prime
                    if (!used_prime[val]) {
                        used_prime[val] = true; // Mark prime as used to prevent redundant loops
                        for (int nxt : prime_to_indices[val]) {
                            if (!visited_idx[nxt]) {
                                visited_idx[nxt] = true;
                                q.push(nxt);
                            }
                        }
                    }
                }
            }
            jumps++;
        }

        return -1; 
    }
};