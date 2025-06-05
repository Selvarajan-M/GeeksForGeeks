class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int l=0,r=0,maxlen=0;
        unordered_map<int,int>mpp;
        while(r<arr.size()){
            mpp[arr[r]]++;
            if(mpp.size()>2){
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0) mpp.erase(arr[l]);
                l++;
            }
            if(mpp.size()<=2){
                maxlen=max(maxlen,r-l+1);
            }

            r++;
        }   
        return maxlen;
    }
};