class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n1 = a.size(), n2 = b.size();
        if (n1 > n2)
            return kthElement(b, a, k); // always binary search on the smaller array

        int low = max(0, k - n2), high = min(k, n1);

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : a[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : b[cut2];

            if (l1 <= r2 && l2 <= r1)
                return max(l1, l2);
            else if (l1 > r2)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }

        return 0; // should not reach here if input k is valid
    }
};
