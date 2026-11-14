auto fastIO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int swimInWater(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        int x[4]={1,-1,0,0};
        int y[4]={0,0,1,-1};
        vector<vector<int>> res(n, vector<int>(m, 1e8));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({a[0][0],{0,0}});
        res[0][0]=a[0][0];
        while(!pq.empty()){
            pair<int,pair<int,int>>p=pq.top();
            pq.pop();
            int money=p.first;
            int row=p.second.first;
            int col=p.second.second;
            if (row == n - 1 && col == m - 1) return money;
            if(money>res[row][col])continue;
            for(int k=0;k<4;k++){
                int r=row+x[k];
                int c=col+y[k];
                if(r<0 || r>=n || c<0 || c>=m )continue;
                int newmoney=max(money,a[r][c]);
                if(newmoney<res[r][c]){
                    res[r][c]=newmoney;
                    pq.push({newmoney,{r,c}});
                }
            }
        }
        return res[n-1][m-1];
    }
};