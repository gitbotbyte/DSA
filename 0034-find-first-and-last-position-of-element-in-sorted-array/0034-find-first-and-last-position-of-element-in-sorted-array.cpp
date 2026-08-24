class Solution {
public:
    int first(vector<int>& nums, int target) {
        int res = -1;
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int guess = (low + high) / 2;
            if (nums[guess] == target) {
                res = guess;
                high = guess - 1;
            } else if (nums[guess] < target) {
                low = guess + 1;
            } else {
                high = guess - 1;
            }
        }
        return res;
    }
    int last(vector<int>& nums, int target) {
        int res2 = -1;
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int guess = (low + high) / 2;
            if (nums[guess] == target) {
                res2 = guess;
                low = guess + 1;
            } else if (nums[guess] < target) {
                low = guess + 1;
            } else {
                high = guess - 1;
            }
        }
        return res2;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstIdx = first(nums, target);
        int lastIdx = last(nums, target);
        return {firstIdx, lastIdx};
    }
};