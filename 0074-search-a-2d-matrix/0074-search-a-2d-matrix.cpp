class Solution {
public:
    int binary(vector<vector<int>>& a, int target,long long low, long long high){
        long long row=-1;
        while(low<=high){
            long long guess=(low+high)/2;
            if(a[guess][0]<=target){
                row=guess;
                low=guess+1;
            }
            else{
                high=guess-1;
            }
        }
        return row;
    }
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n=a.size();
        int row=binary(a,target,0,n-1);
        if(row==-1)return false;
        int n1=a[row].size();
        long long low=0,high=n1-1;
        while(low<=high){
            long long guess=(low+high)/2;
            if(a[row][guess]==target){
                return true;
            }
            else if(a[row][guess]<target)    low=guess+1;
            else high=guess-1;
        }
        return false;
    }
};