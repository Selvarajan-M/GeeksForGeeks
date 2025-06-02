class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        int candidate = 0;

        // Step 1: Find the potential celebrity
        for (int i = 1; i < n; ++i) {
            if (mat[candidate][i] == 1) {
                candidate = i;
            }
        }

        // Step 2: Verify the candidate
        for (int i = 0; i < n; ++i) {
            if (i == candidate) continue;
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0)
                return -1;
        }

        return candidate;
    }
};