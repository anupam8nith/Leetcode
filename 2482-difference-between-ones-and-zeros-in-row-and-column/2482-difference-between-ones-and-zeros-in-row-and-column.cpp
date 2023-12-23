class Solution {
public:
    Solution()
    {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    }
    
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
    {
        int rows= grid.size(), col = grid[0].size();
        
        vector<vector<int>> diff(rows, vector<int>(col));
        
        vector<int> onesCol(col),onesRow(rows), zeroCol(col), zeroRow(rows);
        
        //count zeroes and ones in rows
        for(int i=0;i<rows;i++)
        {
            int count1=0,count0=0;
            
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==0)count0++;
                else if(grid[i][j]==1)count1++;
            }
            
            onesRow[i]=count1;zeroRow[i]=count0;
        }
        
        for(int j=0;j<col;j++)
        {
            int count1=0,count0=0;
            
            for(int i=0;i<rows;i++)
            {
                if(grid[i][j]==0)count0++;
                else if(grid[i][j]==1)count1++;
            }
            
            onesCol[j]=count1;zeroCol[j]=count0;
        }
        
        for(int i=0;i<rows;i++)
            for(int j=0;j<col;j++)
                diff[i][j]=onesRow[i]+onesCol[j]-zeroRow[i]-zeroCol[j];
        
        return diff;
        
    }
};