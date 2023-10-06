class Solution {
public:
    int findTheWinner(int n, int k) 
    {
        cin.tie(0);cout.tie(0);
        
        set<int> s;int idx=0;

        for (int i = 1; i <= n; i++) s.insert(i);

        while (s.size() > 1) 
        {
            idx = (idx + k - 1) % s.size();
            auto it = s.begin();advance(it,idx);
            it = s.erase(it);
        }
        return *s.begin();
    }
};