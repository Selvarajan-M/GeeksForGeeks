class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        stack<int>st;
        int n=arr.size();
        int maxarea=0;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                int currel=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxarea=max(maxarea,arr[currel]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int nse=n;
            int currel=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            maxarea=max(maxarea,arr[currel]*(nse-pse-1));
        }
        return maxarea;
    }
};
