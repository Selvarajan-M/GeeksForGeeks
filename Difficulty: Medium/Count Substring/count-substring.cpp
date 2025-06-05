class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        int lastSeen[3] = {-1, -1, -1};  // To track last seen positions of 'a', 'b', 'c'
        int count = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'b' || s[i] == 'c') {
                lastSeen[s[i] - 'a'] = i;
            }

            // Only count if all three characters have been seen at least once
            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                count += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
            }
        }

        return count;
    }
};