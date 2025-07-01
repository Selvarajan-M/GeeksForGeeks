// User function template for C++

class Solution {
  public:
    int upperBound(vector<int>& arr, int x,int m) {
        int n = arr.size();
        int low = 0, high = n;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= x)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
    int countSmallEqual(vector<vector<int>>&mat,int n,int m,int x){
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=upperBound(mat[i],x,m);
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int low=INT_MAX, high=INT_MIN;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            low=min(low,mat[i][0]);
            high=max(high,mat[i][m-1]);
        }
        int req=(n*m)/2;
        while(low<=high){
            int mid=(low+high)/2;
            int smallEqual=countSmallEqual(mat,n,m,mid);
            if(smallEqual <= req) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};
