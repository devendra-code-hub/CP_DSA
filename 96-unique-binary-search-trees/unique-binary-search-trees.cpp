class Solution {
public:
    long long binomialCoeff(int n, int k) {
        if (k > n - k) {
            k = n - k;
        }

        long long res = 1;

        for (int i = 0; i < k; ++i) {
            res *= (n - i);
            res /= (i + 1);
        }

        return res;
    }

    int numTrees(int n) {
        long long c = binomialCoeff(2 * n, n);
        return c / (n + 1);
    }
};