class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        //  code here
        int n=arr.size();
        vector<int> res(n);
        res[0]=-1;
        stack<int> st;
        st.push(arr[0]);
        for(int i=1;i<n;i++){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                res[i]=-1;
            }
            else{
                res[i]=st.top();
            }
                st.push(arr[i]);
        }
        return res;
    }
};