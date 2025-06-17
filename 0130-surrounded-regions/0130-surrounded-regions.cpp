class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O') 
            {
                q.push({i,0});
                board[i][0]='m';
            }
            if(board[i][n-1]=='O') 
            {
                q.push({i,n-1});
                board[i][n-1]='O';
            }
        }
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O') 
            {
                q.push({0,i});
                board[0][i]='O';
            }
            if(board[m-1][i]=='O') 
            {
                q.push({m-1,i});
                board[m-1][i]='O';
            }
        }
        auto check=[&](int x,int y){
            return x>=0&&x<m&&y>=0&&y<n;
        };
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            board[x][y]='m';
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(check(nx,ny)&&board[nx][ny]=='O')
                {
                    q.push({nx,ny});
                    board[nx][ny]='m';
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]!='m') board[i][j]='X';
                else board[i][j]='O';
            }
        }
    }
};