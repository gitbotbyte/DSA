class Solution {
public:
    int fun(vector<vector<int>>& a, int k, int n, int guess){
        int row=n-1, col=0;
        int count=0;
        while(row>=0 && col<n){
            if(a[row][col]<=guess){
                count+=row+1;
                col++;
            }
            else row--;
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& a, int k) {
        int n=a.size();
        int res=-1;
        int low=a[0][0], high=a[n-1][n-1];
        while(low<=high){
            int guess=(low+high)/2;
            int sol=fun(a,k,n,guess);
            if(sol<k){
                low=guess+1;
            }
            else {
                res=guess;
                high=guess-1;
            }
        }
        return res;
    }
};