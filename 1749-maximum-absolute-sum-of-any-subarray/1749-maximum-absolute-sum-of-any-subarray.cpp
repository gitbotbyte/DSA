class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int minbestending=nums[0];
        int maxbestending=nums[0];
        int res=abs(nums[0]);
        for(int i=1;i<n;i++){
            
            minbestending=min(nums[i],minbestending+nums[i]);
            maxbestending=max(nums[i],maxbestending+nums[i]);
            res=max(res,max(abs(maxbestending),abs(minbestending)));
        }
        return res;
    }
};