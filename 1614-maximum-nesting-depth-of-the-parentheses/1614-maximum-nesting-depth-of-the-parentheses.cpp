class Solution {
public:
    
    int maxDepth(string s) 
    {
        int depth=0, mxdepth=0;
        
        for(char ch: s)
        {
            if(ch=='(')
               mxdepth=max(mxdepth,++depth);
            else if(ch==')')
                depth--;
        }
        
        return mxdepth;
    }
};