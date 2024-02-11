class Solution 
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        vector<pair<int,int>>edges;
        for(auto &it:intervals)
            edges.push_back({it[0],it[1]});
        sort(edges.begin(),edges.end());
        int start=edges[0].first;
        int end=edges[0].second;
        int removeCount=0;
        for(int i=1;i<edges.size();i++)
        {
            if(end>edges[i].first)
            {
                if(end>edges[i].second)
                {
                    start=edges[i].first;
                    end=edges[i].second;
                }
                removeCount++;
            }
            else
              end=edges[i].second;

        }
        return removeCount;
    }
};