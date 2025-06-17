class Solution {
  public:
    int lowerBound(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2; 
            if (arr[mid] < x)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
    int upperBound(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0, high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= x)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int lb=lowerBound(arr,x);
        int n=arr.size();
        if(lb==n||arr[lb]!=x) return {-1,-1};
        return {lb,upperBound(arr,x)-1};
    }
};