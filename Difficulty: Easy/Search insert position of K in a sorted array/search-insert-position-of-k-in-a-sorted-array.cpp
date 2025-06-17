// User function Template for C++

class Solution {
  public:
    int searchInsertK(vector<int> Arr, int N, int k) {
        // code here
        
        int low = 0, high = N;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (Arr[mid] < k)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};