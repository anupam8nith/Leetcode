class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relation, vector<int>& time)
    {

          vector<int>adj[n + 1];
          vector<int>indeg(n + 1, 0), val(n , 0);
        
          for(int i = 0;i < relation.size();i++)
          {
              int u = relation[i][0] - 1, v = relation[i][1] - 1;
              adj[u].push_back(v);
              indeg[v]++;
          }

          queue<pair<int,int>>q;
        
          for(int i = 0;i < n;i++) if(indeg[i] == 0) 
              q.push({i, time[i]}); 
        
         int ans = 0;
        
         while(!q.empty())
         {
             int node = q.front().first , tm = q.front().second;
             q.pop();
             ans = max(ans, tm);
             
             for(auto child : adj[node])
             {
                 indeg[child]--;
                 val[child] = max(val[child], (time[child] + tm));
                 
                 if(indeg[child] == 0) q.push({child, val[child]});
             }
         }
      
      return ans;
    }
};