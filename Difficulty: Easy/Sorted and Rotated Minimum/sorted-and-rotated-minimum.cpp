class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int n=arr.size(),low=0,high=n-1,ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[low]<=arr[high]){
                ans=min(ans,arr[low]);
                break;
            }
            if(arr[low]<=arr[mid]){
                ans=min(ans,arr[low]);
                low=mid+1;
            }
            if(arr[mid]<=arr[high])
            {
                ans=min(ans,arr[mid]);
                high=mid-1;
            }
        }
            return ans;
    
            
    }
};