class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room
    struct data{
      int start;
      int end;
      int pos;
    };
    static bool comp(data val1, data val2){
        return val1.end < val2.end;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        vector<data>arr(n);
        for (int i = 0; i < n; ++i) {
        arr[i] = {start[i], end[i], i};
        }
        sort(arr.begin(),arr.end(),comp);
        int cnt=1,freetime=arr[0].end;
        vector<int>ds={arr[0].pos};
        for(int i=1;i<n;i++){
            if(arr[i].start>freetime){
                cnt++;
                freetime=arr[i].end;
                ds.push_back(arr[i].pos);
            }
        }
        return cnt;
    }
};