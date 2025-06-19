// Function to find square root
// n: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        if (n == 0) return 0;

        int ans = 1;
        int low = 1, high = n;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long val = mid * mid;  // prevent overflow

            if (val <= n) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;

    }
};