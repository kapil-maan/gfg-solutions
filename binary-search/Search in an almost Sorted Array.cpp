class Solution {
    public:
      int findTarget(vector<int>& arr, int target) {
          // code here
          int n=arr.size();
           
          int s=0;
          int e=n -1;
          
          while(s<=e){
              int mid= (s+e)/2;
              
              if(arr[mid]==target) return mid;
              else if(arr[mid-1]==target) return mid-1;
              else if(arr[mid+1]==target) return mid+1;
              
              if(arr[mid]>target) e=mid -2;
              else s=mid+2;
          }
          return -1;
      }
  };


