class Solution {
  public:
    int KthMissingElement(vector<int> &arr, int &k) {
        int n=arr.size(),low = 0, high = n-1;
        
        int total_missing = arr[n - 1] - arr[0] - (n - 1);
        if (k > total_missing) return -1;

        // Binary search to find first index with missing(i) >= k
        while (low <= high) {
            int mid = (low + high) / 2;
            int missing = arr[mid] - arr[0] - mid;

            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // K-th missing is between arr[low - 1] and arr[low]
        return arr[0] + k + low - 1;
    }
};
