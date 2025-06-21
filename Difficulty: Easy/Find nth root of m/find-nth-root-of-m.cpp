class Solution {
  public:
    int func(int base, int exp) {
        long long result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
            if (result > INT_MAX) return INT_MAX; // prevent overflow
        }
        return result;
    }

    int nthRoot(int n, int m) {
        for (int i = 1; i <= m; i++) {
            int val = func(i, n);
            if (val == m)
                return i;
            else if (val > m)
                break;  // ❗break only when result exceeds m
        }
        return -1;
    }
};