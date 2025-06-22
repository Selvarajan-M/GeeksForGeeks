// User function Template for C++

class Solution {
    int fun(const vector<int>& weights, int cap) {
        int day = 1, load = 0;
        for (int weight : weights) {
            if (load + weight > cap) {
                day++;
                load = weight;
            } else {
                load += weight;
            }
        }
        return day;
    }

    int findMax(const vector<int>& weights) {
        int maxi = INT_MIN;
        for (int num : weights) {
            maxi = max(maxi, num);
        }
        return maxi;
    }

    int findSum(const vector<int>& weights) {
        int sum = 0;
        for (int num : weights) {
            sum += num;
        }
        return sum;
    }

  public:
    int leastWeightCapacity(int arr[], int n, int d) {
        vector<int> weights(arr, arr + n);  // Convert to vector

        int low = findMax(weights), high = findSum(weights);
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int noOfDays = fun(weights, mid);

            if (noOfDays <= d) {
                ans = mid;      // valid answer, try to minimize
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
