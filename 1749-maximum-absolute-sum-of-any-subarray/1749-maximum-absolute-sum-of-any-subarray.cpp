class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int minbestending=nums[0];
        int maxbestending=nums[0];
        int res=abs(nums[0]);
        for(int i=1;i<n;i++){
            int v1=nums[i];
            int v2=minbestending+nums[i];
            int v3=maxbestending+nums[i];
            minbestending=min(v1,min(v2,v3));
            maxbestending=max(v1,max(v2,v3));
            res=max(res,max(abs(maxbestending),abs(minbestending)));
        }
        return res;
    }
};