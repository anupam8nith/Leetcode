#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        map[nums[i]]++;
        priority_queue<pair<int,int>> pq;
        for( auto it: map)
        pq.push({it.second,it.first});
        for(int i=0;i<k;i++)
        {
            pair<int,int> val=pq.top();
            pq.pop();
            ans.push_back(val.second);
        }
      return ans;  
    }
};