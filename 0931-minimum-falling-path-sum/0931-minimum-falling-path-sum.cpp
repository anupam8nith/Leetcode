class Solution {
public:
    bool isValid(int x, int y, int n)
    {
        if(x<n && y<n && x>=0 && y>=0) return true;
        
        return false;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();

        for(int i=1;i<n;i++)
            for(int j=0;j<n;j++)
            {
                int temp = INT_MAX;
                
                if(isValid(i-1,j-1,n)) temp= min(temp,matrix[i-1][j-1]);
                if(isValid(i-1,j,n)) temp= min(temp,matrix[i-1][j]);
                if(isValid(i-1,j+1,n)) temp= min(temp,matrix[i-1][j+1]);
                
                matrix[i][j]+=temp;      
            }
        
        return *min_element(matrix[n-1].begin(),matrix[n-1].end());
    }
};