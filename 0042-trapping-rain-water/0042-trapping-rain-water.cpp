class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int total=0;
       
        int prefix_max[n];
        prefix_max[0]=height[0];
        for(int i=1;i<n;i++){
            prefix_max[i]=max(prefix_max[i-1],height[i]);
        }

        int suffix_max[n];
        suffix_max[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suffix_max[i]=max(suffix_max[i+1],height[i]);
        }

        for(int i=0;i<n;i++){
            int leftmax=prefix_max[i];
            int rightmax=suffix_max[i];
            if(height[i]<leftmax && height[i]<rightmax){
                total+=min(leftmax,rightmax)-height[i];
            }
        }
        return total;
    }
};