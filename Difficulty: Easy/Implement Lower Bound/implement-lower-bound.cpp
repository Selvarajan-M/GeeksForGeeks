class Solution {
public:
    int lowerBound(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2; 
            if (arr[mid] < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};