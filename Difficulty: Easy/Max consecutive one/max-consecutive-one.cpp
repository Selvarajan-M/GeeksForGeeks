// User function Template for C++
class Solution {
  public:
    int maxConsecutiveCount(vector<int> &arr) {
        // code here
        int maxZeroes=0,maxOnes=0,currZeroes=0,currOnes=0;
        for(int num:arr){
            if(num==1){
                currOnes++;
                currZeroes=0;
            }
            else{
                currZeroes++;
                currOnes=0;
            }
            maxZeroes=max(maxZeroes,currZeroes);
            maxOnes=max(maxOnes,currOnes);
        }
        return max(maxZeroes,maxOnes);
        
    }
};