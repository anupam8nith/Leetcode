class Solution {
public:
    
    
    int minimumLines(vector<vector<int>>& stockPrices) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = stockPrices.size();
        if(n<=1)
            return 0;
        int count=1;
        
        sort(stockPrices.begin(),stockPrices.end());
        
        for(int i=1;i<n-1;i++)
        {
            long double slope1 = (long double) (stockPrices[i][1] -  stockPrices[i-1][1])*(stockPrices[i+1][0] -  stockPrices[i][0]);
            
             long double slope2 = (long double) (stockPrices[i+1][1] -  stockPrices[i][1])*(stockPrices[i][0] -  stockPrices[i-1][0]);
            
            if(slope1!=slope2)
                count+=1;
        }
        
        return count;
        
        
    }
};

