// User function Template for C++

class Solution {
  public:
    // Function to check if we can reach the last index from 0th index.
    bool canReach(vector<int> &arr) {
        // code here
        int maxInd=0;
        for(int i=0;i<arr.size();i++){
            if(i>maxInd) return false;
            maxInd=max(maxInd,i+arr[i]);
        }
        return true;
    }
};