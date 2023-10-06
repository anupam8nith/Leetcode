class Solution {
public:
    int findTheWinner(int n, int k) 
    {
        set<int> s;
        
        for (int i = 1; i <= n; i++) s.insert(i);

        auto it = s.begin();
        
        while (s.size() > 1) 
        {
            for (int i = 0; i < k-1; i++)
            {
                if (it == s.end())it = s.begin();
                it++;
                if (it == s.end())it = s.begin();
            }        

            it = s.erase(it); 

            if (s.empty()) break;

            if (it == s.end()) it = s.begin();

        }
        return *s.begin();
    }
};