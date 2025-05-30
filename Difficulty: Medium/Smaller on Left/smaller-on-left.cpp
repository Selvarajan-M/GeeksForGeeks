class Solution {
  public:
    vector<int> leftSmaller(vector<int> arr) {
        // code here
        int n=arr.size();
        vector<int>nse(n,-1);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(arr[j]<arr[i]){
                nse[i]=arr[j];
                break;
                }
            }
        }
        return nse;
    }
};