class Solution {
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
public:
     struct cell{
            int x,y;
            int time;
          };
    
    bool valid(cell cur,int n, int m)
    {
                return cur.x >= 0 && cur.x < n && cur.y >= 0 && cur.y < m;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int mx = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<cell> q;
        int frsh_cnt = 0;
        int visited[n][m] ;
        memset(visited,0,sizeof(visited));
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == 2) q.push(cell{i,j,0});
                else if(grid[i][j] == 1) frsh_cnt++;
            }
        }
        
        while( !q.empty() )
        {
            cell curr = q.front();
            q.pop();
            
            if(frsh_cnt == 0)
            {
                mx = curr.time;
            }
            for(int i = 0 ; i < 4 ; i++)
            {
                cell nxt = cell{curr.x+dx[i] , curr.y+dy[i] , curr.time+1};
                if(valid(nxt,n,m) && !visited[nxt.x][nxt.y] && grid[nxt.x][nxt.y] == 1)
                {
                    q.push(nxt);
                    visited[nxt.x][nxt.y] = 1;
                    frsh_cnt--;
                }
            }
        }
        return frsh_cnt == 0 ? mx : -1;
    }
};
