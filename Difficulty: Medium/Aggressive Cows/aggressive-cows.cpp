class Solution {
  public:
    bool fun(vector<int> & arr,int k, int guess){
        int n=arr.size();
        int cows=1;
        int pos=arr[0];
        for(int i=1;i<n;i++){
            int dist=arr[i]-pos;
            if(dist<guess){
                continue;
            }
            cows++;
            pos=arr[i];
        }
        if(cows>=k)return true;
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int low=1;
        int high=arr[n-1]-arr[0];
        int res=-1;
        while(low<=high){
            int guess=(low+high)/2;
            if(fun(arr,k,guess)){
                res=guess;
                low=guess+1;
            }
            else{
                high=guess-1;
            }
        }
    return res;
    }
};