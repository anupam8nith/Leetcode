class Solution {
public:


    int row, col;

    void bfs(vector<vector<int>>& land, int x, int y, pair<int, int> &c1, pair<int, int> &c2)
    {
        if (x < 0 || x >= row || y < 0 || y >= col || land[x][y] == 0) return;

        land[x][y] = 0;
        if(c1.first>=x && c1.second>=y) {c1.first=x;c1.second=y;}
        if(c2.first<=x && c2.second<=y) {c2.first=x;c2.second=y;}

        vector<int> dx = { -1, 0, 0, 1};
        vector<int> dy = {0, -1, 1, 0};

        for (int k = 0; k < 4; k++)
            bfs(land, x + dx[k], y + dy[k],c1,c2);

    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land)
    {
        vector<vector<int>> ans; row = size(land); col = land[0].size();

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                if (land[i][j] == 1)
                {
                    pair<int, int> c1 = {row, col}, c2 = { -1, -1};
                    bfs(land, i, j, c1, c2);
                    vector<int> v = {c1.first, c1.second, c2.first, c2.second};
                    ans.push_back(v);
                }
            }

        return ans;
    }
};