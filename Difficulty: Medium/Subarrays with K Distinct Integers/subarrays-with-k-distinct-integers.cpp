class Solution {
  public:
    int exactlyK(vector<int> &arr, int k) {
        // code here
        if (k <= 0) return 0;
        return atmostK(arr, k) - atmostK(arr, k - 1);
    } 
    int atmostK(vector<int> &arr, int k){
        int l=0,r=0,cnt=0;
        unordered_map<int,int>mpp;
        while(r<arr.size()){
            mpp[arr[r]]++;
            while(mpp.size()>k){
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0)
                    mpp.erase(arr[l]);
                 l++;
                 
            }
          cnt += (r - l + 1);
         r++;
        }
         return cnt;
}
};