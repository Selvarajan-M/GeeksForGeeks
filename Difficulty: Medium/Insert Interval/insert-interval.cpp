// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        vector<vector<int>> res;
        int i=0,n=intervals.size();
        while(i<n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i=i+1;
        }
        while(i<n && intervals[i][0] <=newInterval[1]){
            newInterval[0]=min(newInterval[0], intervals[i][0]);
            newInterval[1]=max(newInterval[1], intervals[i][1]);
            i=i+1;
        }
        res.push_back(newInterval);
        while(i<n){
            res.push_back(intervals[i]);
            i=i+1;
        }
        return res;
    }
};