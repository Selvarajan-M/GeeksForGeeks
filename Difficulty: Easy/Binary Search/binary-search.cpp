class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        int n = arr.size();
        int result=-1;
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == k){
                result=mid;
                high = mid - 1;
            }    
            else if (arr[mid] < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return result;
    }
};
