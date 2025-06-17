class Solution {
  public:

    int findFloor(vector<int>& arr, int x) {
        // Your code here
        int ans=-1;
        int n=arr.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]<=x){
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans;
    }
};
