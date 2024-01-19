class Solution {
public:
    bool isValid(int x, int y, int r, int c)
    {
        if(x<r && y<c && x>=0 && y>=0) return true;
        
        return false;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int r = matrix.size(), c= matrix[0].size(); 

        for(int i=1;i<r;i++)
            for(int j=0;j<c;j++)
            {
                int temp = INT_MAX;
                
                if(isValid(i-1,j-1,r,c)) temp= min(temp,matrix[i-1][j-1]);
                if(isValid(i-1,j,r,c)) temp= min(temp,matrix[i-1][j]);
                if(isValid(i-1,j+1,r,c)) temp= min(temp,matrix[i-1][j+1]);
                
                matrix[i][j]+=temp;      
            }
        
        return *min_element(matrix[r-1].begin(),matrix[r-1].end());
    }
};