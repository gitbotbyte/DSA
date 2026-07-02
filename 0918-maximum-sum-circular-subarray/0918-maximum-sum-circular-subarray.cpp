class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxbestending=nums[0];
        int totalsum=nums[0];
        int minbestending=nums[0];
        int res=nums[0];
        int max_sum = nums[0];
        int min_sum = nums[0];
        for (int i=1;i<n;i++){
            totalsum=totalsum+nums[i];

            maxbestending=max(nums[i],maxbestending+nums[i]);
            max_sum=max(max_sum,maxbestending);

            minbestending=min(nums[i],minbestending+nums[i]);
            min_sum=min(min_sum,minbestending);

        }
        if(max_sum<0)return max_sum;
        return max(res,max(totalsum-min_sum,max_sum));
    }
};