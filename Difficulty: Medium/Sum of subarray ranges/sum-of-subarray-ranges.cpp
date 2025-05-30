class Solution {
public:
    long long subarrayRanges(vector<int>& arr) {
        return sumOfMax(arr) - sumOfMin(arr);
    }

private:
    long long sumOfMin(const vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        long long res = 0;

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || arr[st.top()] >= (i < n ? arr[i] : INT_MIN))) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                long long leftLen = mid - left;
                long long rightLen = right - mid;
                res += leftLen * rightLen * (long long)arr[mid];  // Cast arr[mid] too
            }
            st.push(i);
        }

        return res;
    }

    long long sumOfMax(const vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        long long res = 0;

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || arr[st.top()] <= (i < n ? arr[i] : INT_MAX))) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? -1 : st.top();
                int right = i;
                long long leftLen = mid - left;
                long long rightLen = right - mid;
                res += leftLen * rightLen * (long long)arr[mid];  // Cast arr[mid] too
            }
            st.push(i);
        }

        return res;
    }
};
