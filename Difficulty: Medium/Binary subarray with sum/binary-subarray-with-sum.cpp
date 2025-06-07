class Solution {
  public:
    int numberOfSubarrays(vector<int>& arr, int target) {
        // Your code goes here.
        return atmosttarget(arr,target)-atmosttarget(arr,target-1);
    }
    int atmosttarget(vector<int>&arr,int target)
    {
        if (target < 0) return 0;
        int l=0,r=0,sum=0,cnt=0;
        while(r<arr.size()){
            sum+=arr[r];
            while(sum>target){
                sum=sum-arr[l];
                l=l+1;
            }
            cnt=cnt+(r-l+1);
            r=r+1;
        }
        return cnt;
    }
};