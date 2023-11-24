class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        sort(piles.begin(),piles.end());int ans=0;
        
        deque<int>dq; for(auto& it: piles)dq.push_back(it);
        
        while(!dq.empty())
        {
            dq.pop_back();
            ans+=dq.back(); dq.pop_back();
            dq.pop_front();
        }
        return ans;
    }
};