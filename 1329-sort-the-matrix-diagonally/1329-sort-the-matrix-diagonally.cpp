class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
       unordered_map< int, priority_queue< int, vector<int> , greater<int> >> um;
        
        int m=mat.size();
        int n = mat[0].size();
        
        
        // store in the hash map and sort
        for(int i=0;i<m;i++)   
        {
            for(int j=0;j<n;j++)
                um[i-j].push(mat[i][j]);     //push in priority queue
        }
        
        // put them back at their desired place
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mat[i][j] = um[i-j].top(); //return the top element
                um[i-j].pop(); //pop the top element form the queue
            }
        }
        
        return mat;
    }
};