class Solution 
{
public:
    int m,n; 
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    
    bool isvalid(int x, int y)
    {
        if( x>=m || x<0 ||y>=n || y<0) return false;
        return true;
    }
    
    int dfs(vector<vector<int>>& grid,  vector<vector<bool>>&visited, int sum, int i, int j)
    {
        sum+=grid[i][j];
        
        //perform dfs again and choose the best option
        int val=grid[i][j];
        for(int k=0;k<4;k++)
        {
            int nx = i+dx[k], ny = j+dy[k];
            
            if(isvalid(nx,ny) && !visited[nx][ny] && grid[nx][ny]!=0){
                visited[i][j]=true;
                val = max(val,grid[i][j]+dfs(grid,visited,sum,nx,ny));
                visited[i][j]=false;
            }
        }
        
        return val;
        
    }
    
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        m = size(grid), n = grid[0].size();int ans=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                int sum =0;
                ans = max(ans,dfs(grid,visited, sum, i, j));
            }
        
        return ans;
        
    }
};