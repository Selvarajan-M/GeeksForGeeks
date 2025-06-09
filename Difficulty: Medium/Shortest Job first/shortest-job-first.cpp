// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        int n=bt.size();
        int t=0,wtime=0;
        for(int i=0;i<n;i++){
            wtime+=t;
            t+=bt[i];
        }
        return wtime/n;
    }
};