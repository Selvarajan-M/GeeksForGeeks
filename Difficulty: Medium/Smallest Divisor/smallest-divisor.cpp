class Solution {
  public:
    int sumofD(vector<int>arr,int d,int k,int n){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil((double)arr[i]/(double)d);
        }
        return sum;
    }
    int findmax(vector<int>&arr,int n){
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int n =arr.size(),low=1,high=findmax(arr,n);
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(sumofD(arr,mid,k,n) <= k){
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
            
        }
        return ans;
    }
};
