class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size(), m = mat[0].size();
        int i = 0, j = m - 1;

        while (i < n && j >= 0) {
            if (mat[i][j] == x)
                return true;
            else if (mat[i][j] > x)
                j--;  // move left
            else
                i++;  // move down
        }

        return false;
    }
};
