class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
     int arraysize = grid[0].size(); int rows = grid.size(), ans=0;
    
        for(int i=0;i<rows;i++)
        {
            for(int j=arraysize-1;j>=0;j--) 
                if(grid[i][j]<0)ans++;
                else break;
        }
        return ans;
    }
};