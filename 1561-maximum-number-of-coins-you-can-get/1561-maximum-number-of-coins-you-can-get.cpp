class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        sort(piles.begin(),piles.end());
        
        int n = piles.size() / 3;int total = 0; int j = piles.size() - 2;
        
        for (int i = 0; i < n; ++i) 
        {
            total += piles[j];
            j -= 2;
        }
        
        return total;
    }
};