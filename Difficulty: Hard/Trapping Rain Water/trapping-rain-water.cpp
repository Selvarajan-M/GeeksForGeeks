class Solution {
public:
    int maxWater(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0, total = 0;

        while (l < r) {
            if (arr[l] <= arr[r]) {
                if (arr[l] < lmax)
                    total += lmax - arr[l];
                else
                    lmax = arr[l];
                l++;
            } else {
                if (arr[r] < rmax)
                    total += rmax - arr[r];
                else
                    rmax = arr[r];
                r--;
            }
        }

        return total;
    }
};