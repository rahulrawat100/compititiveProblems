class Solution {
public:

    void Insert(vector<vector<char>>& board, queue<pair<int,int>>& q, vector<vector<bool>>& trav, int i, int j)
    {
        int m = board.size();
        int n = board[0].size();
        if(i<0 || j<0 || i==m || j==n || trav[i][j] || board[i][j]=='X')
            return;
        trav[i][j]=true;
        q.push({i, j});
    }
    void bfs(queue<pair<int,int>>& q, vector<vector<bool>>& trav,vector<vector<char>>& board)
    {
        if(q.empty())
            return;
        int s= q.size();

        while(s-->0)
        {
            int i = q.front().first;
            int j= q.front().second;
            trav[i][j]=true;
            q.pop();
            Insert(board, q, trav, i+1, j);
            Insert(board, q, trav, i-1, j);
            Insert(board, q, trav, i, j+1);
            Insert(board, q, trav, i, j-1);
        }    
        bfs(q, trav, board);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++)
        {
            if(board[i][0]=='O')
               q.push({i, 0});
            if(board[i][n-1]=='O')
               q.push({i, n-1});   
        }
        for(int i=0; i<n; i++)
        {
            if(board[0][i]=='O')
               q.push({0, i});
            if(board[m-1][i]=='O')
               q.push({m-1, i});   
        }    
        vector<vector<bool>> trav(m, vector<bool>(n));
        cout<<q.size()<<endl;
        bfs(q, trav, board);

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(!trav[i][j])
                    board[i][j]='X';
            }
        }    
    }
};