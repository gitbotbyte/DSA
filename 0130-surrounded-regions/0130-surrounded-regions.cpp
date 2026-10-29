class Solution {
public:
    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};
    bool valid(vector<vector<char>>& board,int r, int c, int rows, int cols){
        if(r>=0 && r<rows && c>=0 && c<cols)return true;
        return false;
    }
    void dfs(vector<vector<char>>& board, int r, int c, int rows, int cols){
        board[r][c]='#';
        for(int k=0;k<4;k++){
            int nrow=r+x[k];
            int ncol=c+y[k];
            if(valid(board,nrow ,ncol, rows, cols) && board[nrow][ncol]=='O'){
                dfs(board,nrow,ncol, rows,cols);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int rows=board.size();
        int cols=board[0].size();
        for(int i=0;i<cols;i++){
            if(board[0][i]=='O'){
                dfs(board, 0, i, rows, cols);
            }  
        }
        for(int i=0;i<cols;i++){
            if(board[rows-1][i]=='O'){
                dfs(board, rows-1, i, rows, cols);
            }  
        }
        for(int i=0;i<rows;i++){
            if(board[i][0]=='O'){
                dfs(board, i,0 , rows, cols);
            }  
        }
        for(int i=0;i<rows;i++){
            if(board[i][cols-1]=='O'){
                dfs(board, i, cols-1, rows, cols);
            }  
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='O')board[i][j]='X';
                else if(board[i][j]=='#')board[i][j]='O';
            }
        }
        return;
    }
};