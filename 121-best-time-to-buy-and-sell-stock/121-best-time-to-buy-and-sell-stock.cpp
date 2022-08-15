class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
      int select=0, profit=INT_MIN,max_profit=0;
        
        
        
        for(long int i=0;i<prices.size();i++)
        {
            if(prices[select]>prices[i])
                select=i;
            else
                max_profit= max(max_profit, prices[i]-prices[select]);
        }
        
        return max_profit;
    }
};