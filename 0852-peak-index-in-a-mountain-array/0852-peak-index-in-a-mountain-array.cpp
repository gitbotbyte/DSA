class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        int res=0;
        while(low<=high){
            int guess=(low+high)/2;
            if(arr[guess]<arr[guess+1]){
                res=guess+1;
                low=guess+1;
            }
            else{
                high=guess-1;
            }
        }
        return res;
    }
};