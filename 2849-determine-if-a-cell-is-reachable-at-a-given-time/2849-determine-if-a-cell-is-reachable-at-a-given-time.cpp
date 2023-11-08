class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) 
    {
      int delx= abs(sx-fx);
        int dely= abs(sy-fy);
        
        if(delx==0 && dely==0)
            return t!=1;
        
        if(delx<=t && dely <=t)
            return true;
        
        return false;
    }
};