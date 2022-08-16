class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
    {
        int n = mat.size()*mat[0].size();
        if((n!=r*c))
           return mat;
        
        
         vector<vector<int>> ans(r,vector<int> (c));
        
       for(int i=0;i<n;i++)
       {
           ans[i/c][i%c]=mat[i/mat[0].size()][i%mat[0].size()];
        }
        
        
        return ans;
    }
};