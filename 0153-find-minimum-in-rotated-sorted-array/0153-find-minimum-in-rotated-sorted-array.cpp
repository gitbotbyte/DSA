class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int res=-1;
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int guess = (low + high) / 2;
            if (nums[guess] > nums[n-1]) {
                low = guess + 1;
            } else {
                res=guess;
                high = guess - 1;
            }
        }
        return nums[res];
    }
};