class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1) {
                    if ((i - 1) < 0 || grid[i - 1][j] == 0){
                        ans += 1;
                    }
                    if ((j - 1) < 0 || grid[i][j - 1] == 0){
                        ans += 1;
                    }
                    if ((j + 1) >= grid[0].size() || grid[i][j + 1] == 0){
                        ans += 1;
                    }
                    if ((i + 1) >= grid.size() || grid[i + 1][j] == 0) {
                        ans += 1;
                    }
                }
            }
        }
        return ans;
    }
};