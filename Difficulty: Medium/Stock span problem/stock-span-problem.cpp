class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        int n = arr.size();
        vector<int> answer(n);
        stack<pair<int, int>> st;  // pair<value, index>

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && st.top().first <= arr[i]) {
                st.pop();
            }
            answer[i] = st.empty() ? (i + 1) : (i - st.top().second);
            st.push({arr[i], i});
        }

        return answer;
    }
};