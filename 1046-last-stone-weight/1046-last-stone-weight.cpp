class Solution {
public:
    int lastStoneWeight(vector<int>& a) {
        priority_queue<int> pq;
        for (int i = 0; i < a.size(); i++) {
            pq.push(a[i]);
        }
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