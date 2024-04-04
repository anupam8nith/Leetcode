class Solution {
public:
    
    int maxDepth(string s) 
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
};