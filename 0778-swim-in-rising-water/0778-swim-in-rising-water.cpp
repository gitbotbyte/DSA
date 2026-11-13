class Solution {
public:
    bool bfs(vector<vector<int>>& a, int n, int m, int money){
        int x[4]={1,-1,0,0};
        int y[4]={0,0,1,-1};
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n);
        for(int i=0;i<n;i++){
            vector<int>t(m,0);
            vis[i]=t;
        }
        q.push({0,0});
        vis[0][0]=1;
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            int row=p.first;
            int col=p.second;
            if(row==n-1 && col==m-1){
                return true;
            }
            for (int k=0;k<4;k++){
                int r=row+x[k];
                int c=col+y[k];
                if(r>=0 && r<n && c>=0 && c<m && vis[r][c]==0 && money>=a[r][c]){
                    q.push({r,c});
                    vis[r][c]=1;    
                }
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        int low=a[0][0];
        int high=n*n-1;
        int res=0;
        while(low<=high){
            int guess=(low+high)/2;
            if(bfs(a,n,m,guess)){
                res=guess;
                high=guess-1;
            }
            else{
                low=guess+1;
            }
        }
        return res;
    }
};