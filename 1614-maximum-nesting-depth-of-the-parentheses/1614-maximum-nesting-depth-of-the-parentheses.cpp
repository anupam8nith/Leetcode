class Solution {
public:
    
    int vps(string& s)
    {
        int depth=0, mxdepth=0;
        
        for(char ch: s)
        {
            if(ch=='(')
                depth++;
            else if(ch==')')
                depth--;
            
            mxdepth=max(mxdepth,depth);
        }
        
        return mxdepth;
    }
    
    int maxDepth(string s) 
    {
        return vps(s);
    }
};