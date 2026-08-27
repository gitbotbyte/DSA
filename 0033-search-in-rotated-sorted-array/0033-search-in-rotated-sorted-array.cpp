class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int res = -1;
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int guess = (low + high) / 2;
            if (nums[guess] > nums[n - 1]) {
                low = guess + 1;
            } else {
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
    int binary(vector<int>& nums, int target, int low, int high) {
        int sol = -1;
        int n = nums.size();
        while (low <= high) {
            int guess = (low + high) / 2;
            if (nums[guess] == target) {
                sol = guess;
                break;
            } else if (nums[guess] > target)
                high = guess - 1;
            else
                low = guess + 1;
        }
        return sol;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int minindex = findMin(nums);
        int firsthalf = binary(nums, target, 0, minindex-1);
        int sechalf = binary(nums, target, minindex, n - 1);
        if (firsthalf == -1) {
            return sechalf;
        } else
            return firsthalf;
    }
};