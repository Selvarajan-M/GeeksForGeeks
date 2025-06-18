// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int low=0,high=n-1;
        int ans=INT_MAX,index=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[low]<=arr[high]){
                if(arr[low]<ans){
                    index=low;
                    ans=arr[low];//minimum number
                }
                break;
            }
            if(arr[low]<=arr[mid]){
                if(arr[low]<ans){
                    index=low;
                    ans=arr[low];
                }
                low=mid+1;
            }
            else{
                if(arr[mid]<=arr[high]){
                    index=mid;
                    ans=arr[mid];
                }
                high=mid-1;
            }
        }
        return index;
    }
};
