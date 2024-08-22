#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution 
{
public:
    long long maxPoints(vector<vector<int>>& points) 
    {
        int row = points.size(), col = points[0].size();
        vector<long long> dp(col, 0);

        // Initialize dp
        for(int j = 0; j < col; j++)
            dp[j] = points[0][j];

        for(int i = 1; i < row; i++)
        {
            vector<long long> left_max(col), right_max(col);

            // Left to right pass
            left_max[0] = dp[0];
            for(int j = 1; j < col; j++)
                left_max[j] = max(left_max[j-1], dp[j] + j);

            // Right to left pass
            right_max[col-1] = dp[col-1] - (col-1);
            for(int j = col-2; j >= 0; j--)
                right_max[j] = max(right_max[j+1], dp[j] - j);

            // Update dp for the current row
            for(int j = 0; j < col; j++)
                dp[j] = points[i][j] + max(left_max[j] - j, right_max[j] + j);
        }

        // Find the maximum value in the last row
        return *max_element(dp.begin(), dp.end());
    }
};