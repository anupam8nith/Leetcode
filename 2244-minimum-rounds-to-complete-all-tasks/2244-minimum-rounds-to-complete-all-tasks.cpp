class Solution {
public:
    
    int minimumRounds(vector<int>& tasks) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        map<int,int> um;
        
       for(auto t: tasks)
       um[t]++;
        
        // stored in sorted order
        int ans=0;
        
        for(auto x: um)
        {
            if(x.second==1)
            return -1;
            else
            {
                while(x.second>0)
                {
                    if(x.second>=3)
                    {
                        ans++;
                        x.second-=3;
                    }
                    else if(x.second<=2)
                    {
                        ans++;
                        
                        if(x.second>=2)
                            x.second-=2;
                        else
                             x.second-=1;
                    }
                }
            }
            
        }
        return ans;
    }
};