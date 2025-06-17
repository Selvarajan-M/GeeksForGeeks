class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= target)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};
