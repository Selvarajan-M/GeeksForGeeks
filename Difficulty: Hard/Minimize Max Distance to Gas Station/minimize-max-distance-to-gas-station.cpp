class Solution {
  public:
    int countOfGasStations(vector<int>& stations, double dist) {
        int cnt = 0;
        for (int i = 1; i < stations.size(); i++) {
            double gap = stations[i] - stations[i - 1];
            cnt += (int)(gap / dist);
        }
        return cnt;
    }

    double findSmallestMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        double low = 0, high = 0;

        for (int i = 1; i < n; i++) {
            high = max(high, (double)(stations[i] - stations[i - 1]));
        }

        while (high - low > 1e-6) {
            double mid = (low + high) / 2.0;
            int cnt = countOfGasStations(stations, mid);
            if (cnt > k) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return high;
    }
};
