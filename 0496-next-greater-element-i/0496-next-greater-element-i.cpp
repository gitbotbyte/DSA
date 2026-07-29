class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n=nums2.size();
        vector<int> res;
        stack<int> st;
        st.push(nums2[n-1]);
        unordered_map<int,int> mp;
        mp[nums2[n-1]] = -1;
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mp[nums2[i]] = -1;
            }
            else if(st.top()>nums2[i]){
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<n1;i++){
            res.push_back(mp[nums1[i]]);
        }
        return res;
    }
};