class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& v) 
    {
        for(int i=1;i<(v.size()-1);i++) 
            if( (v[0][1]-v[1][1])*(v[i][0]-v[i+1][0]) != (v[i][1]-v[i+1][1])*(v[0][0]-v[1][0]) ) 
                return false;
            
        return true;
    }
};