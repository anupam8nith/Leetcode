class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = size(temperatures);
        
        vector<int> ans(n,0);
        
        //implementing monotonic stack
        
        stack<int> s;
        s.push(0);
        
        for(int i=1;i<n;i++)
        {
            if(s.empty())
            {
                s.push(i);
                continue;
            }
            
            while(s.empty()==0 && temperatures[s.top()]<temperatures[i])
            {
                ans[s.top()] = (i - s.top());
                
                s.pop();
            }
            
            s.push(i);
        }
        
        while(s.empty()==false)
        {
            ans[s.top()]=0;
            s.pop();
        }
        
        return ans;
        
    }
};