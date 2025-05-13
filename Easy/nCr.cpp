//easy
// without dp


class Solution {
  public:
    int nCr(int n, int r) {
        // code here
        if(r>n) return 0;
        if(r==0 || r==n ) return 1;
        if(r==1 || r==n-1) return n;
        
        if(n-r<r) r=n-r; // just to simplify more, to reduce number of iterations/computations
        
        double ans=1;
        for(int i=r; i>=1; i--){
            ans*= (double) (n -i + 1)/i;
        }
        
        return (int) (ans + 0.5); // rounding instead of truncating 
    }
};