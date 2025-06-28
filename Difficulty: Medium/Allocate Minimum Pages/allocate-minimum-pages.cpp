class Solution {
  public:
    
    int findmax(vector<int> &arr){
    int maxi=INT_MIN;
    for(int num:arr){
        maxi=max(maxi,num);
    }
    return maxi;
    }
    
    int findsum(vector<int>&arr){
        int sum=0;
        for(int num:arr){
            sum+=num;
        }
        return sum;
    }
    
    int func(vector<int> &arr,int pages){
        int stu=1,pagesallocate=0,n=arr.size();
        for(int i=0;i<n;i++){
            if(pagesallocate+arr[i]<=pages){
                pagesallocate+=arr[i];
            }
            else{
                stu++;
                pagesallocate=arr[i];
            }
        }
        return stu;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k > n) return -1;
        int low=findmax(arr),high=findsum(arr);
        while(low<=high){
            int mid=(low+high)/2;
            int noOfStud=func(arr,mid);
            if(noOfStud > k) low=mid+1;
            else high=mid-1;
        }
        return low; 
    }
};