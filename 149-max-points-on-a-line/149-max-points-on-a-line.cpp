class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        if(n<=2)
            return n;
        
        int count=0;
        
        //diagonal points
        for(int i=0;i<n-1;i++)
        {
            unordered_map<double,int> um;
            for(int j=i+1;j<n;j++)
            {
                    double dx = points[j][0] - points[i][0];
                    double dy = points[j][1] - points[i][1];
                    
                    if(dx && dy)
                    {
                        um[(double)dy/dx]++;
                        count=max(count,um[(double)dy/dx]+1);
                    }
                    
                        
                
            }
        }
        
        //x && y elements
        unordered_map<int,int> umx,umy;
        
        for(auto p: points)
        {
            umx[p[0]]++;
            umy[p[1]]++;
            count = max(count, umx[p[0]]);
            count = max(count, umy[p[1]]);
        }
        umx.clear();
        umy.clear();
        
        return count;
    }
};