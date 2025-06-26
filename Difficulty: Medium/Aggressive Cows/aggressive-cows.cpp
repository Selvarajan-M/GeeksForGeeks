// User function Template for C++

class Solution {
  public:
    bool canWePlace(vector<int>&stalls,int dist,int k){
        int cntcows=1,last=stalls[0];
        int n=stalls.size();
        for(int i=1;i<n;i++){
            if(stalls[i]-last>=dist){
                cntcows++;
                last=stalls[i];
            }
            
        }
        if(cntcows>=k) return true;
        else return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(),stalls.end());
        
        int n=stalls.size(),low=1,high=stalls[n - 1] - stalls[0],ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(canWePlace(stalls,mid,k)){
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return ans; 
    }
};