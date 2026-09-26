class Solution {
public:
    int lastStoneWeight(vector<int>& a) {
        priority_queue<int> pq(a.begin(),a.end());
        
        while (pq.size()>=2) {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if(x!=y){
                pq.push(y-x);
            }
        }
        if(!pq.empty())return pq.top();
        return 0;
    }
};