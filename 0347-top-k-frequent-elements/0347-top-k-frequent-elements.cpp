#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
       unordered_map<int,int>map;
       for(auto ele: nums)map[ele]++;
           
       using int_int=pair<int,int>;
       vector<int_int>v; vector<int> ans;
       
       for(auto it: map)v.push_back({it.second,it.first});
       
       sort(v.begin(),v.end(),greater<int_int>());
        
       for(int i=0;i<k;i++)ans.push_back(v[i].second);
           
       return ans;
    }
};