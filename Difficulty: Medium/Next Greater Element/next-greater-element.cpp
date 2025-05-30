class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n, -1);  // Initialize with -1
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            // Pop all elements smaller than or equal to arr[i]
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // If stack is not empty, then top is the next greater element
            if (!st.empty()) {
                nge[i] = st.top();
            }

            // Push current element to stack
            st.push(arr[i]);
        }

        return nge;
    }
};
