class Solution {
public:
    int buyChoco(vector<int>& prices, int money) 
    {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        int mn1=INT_MAX, mn2=INT_MAX;
        
        for(auto& it: prices)
        {
            if(mn1>=it){mn2=mn1;mn1=it;continue;}
            
            if(it<mn2 && it>mn1)mn2=it;
        }
        
        return mn1+mn2<=money ? money-(mn1+mn2) : money;
    }
};