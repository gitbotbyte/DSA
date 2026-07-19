class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=i+1;
        int count=1;
        while(j<n){
            if(nums[i]==nums[j]){
                j++;
            }
            else {
                i++;
                nums[i]=nums[j];
                j++;
                count++;
            }
        }
        return count;

    }
};