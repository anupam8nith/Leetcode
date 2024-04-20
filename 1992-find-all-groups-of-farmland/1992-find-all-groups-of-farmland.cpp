class Solution {
public:
    int row, col;

    void findBoundaries(vector<vector<int>>& land, int x, int y, pair<int, int>& c1, pair<int, int>& c2) {
        queue<pair<int, int>> q;
        q.push({x, y});
        land[x][y] = 0;

        while (!q.empty()) {
            auto [curX, curY] = q.front();
            q.pop();

            c1.first = min(c1.first, curX);
            c1.second = min(c1.second, curY);
            c2.first = max(c2.first, curX);
            c2.second = max(c2.second, curY);

            vector<int> dx = { -1, 0, 0, 1};
            vector<int> dy = {0, -1, 1, 0};

            for (int k = 0; k < 4; k++) {
                int newX = curX + dx[k];
                int newY = curY + dy[k];
                if (newX >= 0 && newX < row && newY >= 0 && newY < col && land[newX][newY] == 1) {
                    q.push({newX, newY});
                    land[newX][newY] = 0;
                }
            }
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans; 
        row = land.size(); 
        col = land[0].size();

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                if (land[i][j] == 1) {
                    pair<int, int> c1 = {i, j}, c2 = {i, j};
                    findBoundaries(land, i, j, c1, c2);
                    ans.push_back({c1.first, c1.second, c2.first, c2.second});
                }
            }

        return ans;
    }
};