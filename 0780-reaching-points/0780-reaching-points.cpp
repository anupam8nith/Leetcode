class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) 
        {
            if (tx == sx && ty == sy) return true;
            
            if (tx > ty) tx -= max((tx - sx) / ty, 1) * ty;
            
            else ty -= max((ty - sy) / tx, 1) * tx;
            
        }
        return false;
    }
};


// WORST SOLUTION EXPONENTIAL TIME COMPLEXITY;

// class Solution {
// public:
//     bool ans=false;
    
//     void solve(int nx,int ny, int x, int y)
//     {
//         if(nx>x || ny>y)
//             return;
//         else if(nx==x && ny==y)
//         {
//             ans=true;
//             return;
//         }
        
//         solve(nx+ny,ny,x,y);
//         solve(nx,ny+nx,x,y);
        
//         return;
//     }
    
//     bool reachingPoints(int sx, int sy, int tx, int ty) 
//     {
        
//         solve(sx,sy,tx,ty);
        
//         return ans;
//     }
// };