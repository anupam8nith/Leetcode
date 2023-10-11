#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution 
{
public:

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) 
    {
         vector<int> start, end;
        for (auto& f : flowers)
            start.push_back(f[0]), end.push_back(f[1]);
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        vector<int>ans;
        
        for (int time : people) 
        {
            int started = upper_bound(start.begin(), start.end(), time) - start.begin();
            int ended = lower_bound(end.begin(), end.end(), time) - end.begin();
            ans.push_back(started - ended);
        }
        return ans;
    }
};