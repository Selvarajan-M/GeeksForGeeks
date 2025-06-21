class Solution {
  public:
    long long findTotalHrs(vector<int>& arr, int mid){
        long long totalhrs=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            totalhrs+=ceil((double)arr[i]/(double)mid);
        }
        return totalhrs;
    }
    int findMax(vector<int>& arr){
        int maxi=INT_MIN;
        int n=arr.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }

    int kokoEat(vector<int>& arr, int k) {
        // Code here
        long long low=1, high=findMax(arr);
        int ans=INT_MAX;
        int n=arr.size();
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long totalhrs=findTotalHrs(arr,mid);
            if(totalhrs <= k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};