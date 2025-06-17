class Solution {
  public:
    int firstOccurences(vector<int>&arr,int x){
     int n=arr.size();
     int low=0,high=n-1;
     int first=-1;
     while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==x){
            first=mid;
            high=mid-1;
        }   
        else if(arr[mid]<x)
        low=mid+1;
        else
        high=mid-1;
        }
        return first;   
    }
    int lastOccurences(vector<int>&arr,int x){
     int n=arr.size();
     int low=0,high=n-1;
     int last=-1;
     while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==x){
            last=mid;
            low=mid+1;;
        }   
        else if(arr[mid]<x)
        low=mid+1;
        else
        high=mid-1;
        }
        return last;   
    }
   
    int countFreq(vector<int>& arr, int target) {
         // code here
       int first=firstOccurences(arr,target);
       if(first==-1) return 0;
       int last=lastOccurences(arr,target);
       return last-first+1;
    }
};
