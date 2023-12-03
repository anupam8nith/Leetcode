class Solution 
{
public:
    int numPoints(vector<vector<int>>& points, int r) 
    {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        
        int res = 1;
        // use a constant variable to store r * r
        const double R2 = (double) r * r; int n = points.size();
        
        for (int i = 0; i < n - 1; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                double d = (pow(x1 - x2, 2) + pow(y1 - y2, 2)) / 4.0;
                
                if (d > R2) continue;
                
                double x0 = (x1 + x2) / 2.0 + (y2 - y1) * pow((R2 - d), 0.5) / pow((d * 4), 0.5);
                double y0 = (y1 + y2) / 2.0 - (x2 - x1) * pow((R2 - d), 0.5) / pow((d * 4), 0.5);
                
                int cnt = 0;
                
                for (vector<int>& point : points) // use a helper function to check if a point is inside the dartboard
                    if (is_inside(point, x0, y0, R2)) cnt++;
                
                res = max(res, cnt);
                
                x0 = (x1 + x2) / 2.0 - (y2 - y1) * pow((R2 - d), 0.5);
                y0 = (y1 + y2) / 2.0 + (x2 - x1) * pow((R2 - d), 0.5);
                
                cnt = 0;
                
                for (vector<int>& point : points)
                    if (is_inside(point, x0, y0, R2)) cnt++;
                
                res = max(res, cnt);
            }
        }
        
        return res;
    }
    
    
    bool is_inside(vector<int>& point, double x0, double y0, double R2) 
    {
        double x = point[0];
        double y = point[1];
        return pow((x - x0), 2) + pow((y - y0), 2) <= R2 + 0.00001;
    }
};
