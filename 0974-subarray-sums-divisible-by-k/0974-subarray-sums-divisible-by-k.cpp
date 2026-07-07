class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int res=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0){
                rem+=k;
            }
            int freq=mp[rem];
            res+=freq;
            mp[rem]++;
        }
        return res;
    }
};