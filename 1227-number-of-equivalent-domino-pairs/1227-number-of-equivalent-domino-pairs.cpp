class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            unordered_map<string,int> um;
            for(auto v: dominoes)
                {
                    string s ="";
                    s += char(min(v[0],v[1]));
                    s += char(max(v[0],v[1]));
                    um[s]++;
                }
            int answer=0;
            for(auto it:um)
            {
                int n = it.second;
                if(n>1)
                    answer+=n*(n-1)/2;
            }
            
                return answer;
        }
    };