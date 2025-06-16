class Solution {
  public:
    int minCandy(vector<int> &arr) {
        // code here
        int sum=1,i=1;
        int n=arr.size();
        while(i<n){
            if(arr[i]==arr[i-1])
            {
                sum=sum+1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && arr[i]>arr[i-1])
            {
                peak++;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n&& arr[i]<arr[i-1]){
                sum+=down;
                i++;
                down++;
            }
            if(down>peak){
                sum+=down-peak;
            }
        }
        return sum;
    }
};
