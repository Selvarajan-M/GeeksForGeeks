// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int>pq;
        for(int num: arr){
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        if (pq.size() < k){
            return -1;
        }
        return pq.top();
    }
};