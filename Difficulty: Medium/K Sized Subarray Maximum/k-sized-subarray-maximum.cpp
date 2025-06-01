class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector<int> list;
        deque<int>dq;
        for(int i=0;i<n;i++){
            if(!dq.empty()&&dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty()&&arr[dq.back()]<=arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if( i>=k-1) list.push_back(arr[dq.front()]);
        }
        return list;
    }
};