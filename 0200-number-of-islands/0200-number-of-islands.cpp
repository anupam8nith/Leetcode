class Solution 
{
public:

    int row,col;

    void dfs(vector<vector<char>>& grid,int x,int y)
    {
        if(x<0 || x>=row || y<0 || y>=col || grid[x][y]=='0') return;

        grid[x][y]='0';

        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, -1, 1, 0};

        for(int k=0;k<4;k++)
            dfs(grid,x+dx[k],y+dy[k]);

    }
    
    
    int numIslands(vector<vector<char>>& grid) 
    {
        row = size(grid), col = size(grid[0]); int island=0;

        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                if(grid[i][j]!='0')
                {
                    dfs(grid,i,j);
                    island++;
                }

        return island;
    }
};