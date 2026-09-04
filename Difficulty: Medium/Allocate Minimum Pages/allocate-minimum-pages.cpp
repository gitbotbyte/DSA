class Solution {
  public:
    bool fun(vector<int> &arr, int k ,int n, long limit){
        int stu=1;
        long long page=0;
        for(int i=0;i<n;i++){
            if (arr[i] > limit) return false;
            if(page+arr[i]<=limit){
                page+=arr[i];
            }
            else{
                stu++;
                page=arr[i];
                if(stu>k)return false;
            }
        }
        return true;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>n)return -1;
        long long res=-1;
        long long low=*max_element(arr.begin(),arr.end());
        long long high=accumulate(arr.begin(),arr.end(),0LL);
        while(low<=high){
            long long guess=(low+high)/2;
            if(fun(arr,k,n,guess)){
                res=guess;
                high=guess-1;
            }
            else{
                low=guess+1;
            }
        }
        return res;
    }
};