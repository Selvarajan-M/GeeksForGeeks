class Solution {
  public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        // Your Code goes here.
        int n=greed.size();
        int m=cookie.size();
        int l=0,r=0,count=0;
        sort(greed.begin(),greed.end());
        sort(cookie.begin(),cookie.end());
        while(l<n && r<m)
        {
            if(greed[l]<=cookie[r])
            {
                count++;
                l++;
                r++;
            }
            else
            {
            r++;
                
            }
        }
        return count;
    }
};