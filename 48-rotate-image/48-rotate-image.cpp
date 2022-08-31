class Solution {
public:
    void rotate(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        //take transpose and reverse it;
        
        //take transpose
        int temp=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<i;j++)
            {
                temp=mat[i][j];
                mat[i][j]=mat[j][i];
                mat[j][i]=temp;
            }
                
        //reverse every vector in mat
        for(auto &x: mat)
            reverse(x.begin(),x.end());
        
        return;
        
    }
};