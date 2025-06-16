#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    struct Item {
        int value;
        int weight;
    };

    static bool comp(const Item& a, const Item& b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<Item> items;
        for (int i = 0; i < n; ++i) {
            items.push_back({val[i], wt[i]});
        }

        // Use stable_sort to ensure consistency when value/weight ratios are equal
        stable_sort(items.begin(), items.end(), comp);

        double totalVal = 0.0;

        for (int i = 0; i < n && capacity > 0; ++i) {
            if (items[i].weight <= capacity) {
                totalVal += items[i].value;
                capacity -= items[i].weight;
            } else {
                totalVal += ((double)items[i].value / items[i].weight) * capacity;
                capacity = 0;
            }
        }

        return totalVal;
    }
};
