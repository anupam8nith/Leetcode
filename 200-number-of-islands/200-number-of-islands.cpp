class Solution {
public:
    
    void DFS(vector<vector<char>>& grid, int i, int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
            return;
        
        if(grid[i][j] == '2' || grid[i][j] == '0')
            return;
        
        // mark the current as visited
        grid[i][j] = '2';
        
        // do DFS in all 4 directions
        DFS(grid, i+1, j);
        DFS(grid, i, j-1);
        DFS(grid, i-1, j);
        DFS(grid, i, j+1);
        
        
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int count=0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                
                // do DFS in case has not been visited and there is land
                
                if(grid[i][j] == '1') {
                    DFS(grid, i, j);
                    ++count;
                } 
            }
        }
        
        return count;
    }
};