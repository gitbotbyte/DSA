class Solution {
public:
    long long fun(vector<int> & a,int k,int n){
        long long h1=0;
        for(int i=0;i<n;i++){
            h1=h1+a[i]/k;
            if(a[i]%k!=0)h1++;   
        }
        return h1;
    }
    int minEatingSpeed(vector<int>& a, int h) {
        int n=a.size();
        int low=1;
        int high=*max_element(a.begin(), a.end());
        int res=-1;
        while(low<=high){
            int guess=(low+high)/2;
            long long hour=fun(a,guess,n);
            if(hour>h){
                low=guess+1;
            }
            else{
                res=guess;
                high=guess-1;
            }
        }
    return res;
    }
};