class Solution {
  public:
    int largestHistogram(vector<int> &arr) {
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
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int n=mat.size(),m=mat[0].size(),maxarea=0;
        vector<vector<int>>prefsum(n,vector<int>(m, 0));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=mat[i][j];
                if(mat[i][j]==0) sum=0;
                prefsum[i][j]=sum;
            }
        }
        for(int i=0;i<n;i++){
            maxarea=max(maxarea,largestHistogram(prefsum[i]));
        }
        return maxarea;
    }
};