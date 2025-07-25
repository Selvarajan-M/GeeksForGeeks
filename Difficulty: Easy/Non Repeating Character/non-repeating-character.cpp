
class Solution {
  public:
    char nonRepeatingChar(string &s) {
        // Your code here
        int n=s.length();
        if(n==0)
        return '$';
        vector<int>count(256,0);
        for(int i=0;i<n;i++){
            count[s[i]]++;
        }
        for(int i=0;i<n;i++){
            if(count[s[i]]==1)
            return s[i];
        }
        return  '$';
    }
};