class Solution {
public:
    void rotate(vector<vector<int>>& mat) 
    {
        reverse(mat.begin(),mat.end());
        
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<i;j++)
                swap(mat[i][j],mat[j][i]);
        
        return;
        
    }
};

//4ms

// int m = mat.size();
//         int n = mat[0].size();
//         //take transpose and reverse it;
        
//         //take transpose
//         int temp=0;
//         for(int i=0;i<m;i++)
//             for(int j=0;j<i;j++)
//                 swap(mat[i][j],mat[j][i]);
                
//         //reverse every vector in mat
        
//         for(auto &x: mat)
//             reverse(x.begin(),x.end());
        
//         return;


//other methods
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
// void rotate(vector<vector<int> > &matrix) {
//     reverse(matrix.begin(), matrix.end());
//     for (int i = 0; i < matrix.size(); ++i) {
//         for (int j = i + 1; j < matrix[i].size(); ++j)
//             swap(matrix[i][j], matrix[j][i]);
//     }
// }

/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
// void anti_rotate(vector<vector<int> > &matrix) {
//     for (auto vi : matrix) reverse(vi.begin(), vi.end());
//     for (int i = 0; i < matrix.size(); ++i) {
//         for (int j = i + 1; j < matrix[i].size(); ++j)
//             swap(matrix[i][j], matrix[j][i]);
//     }
// }