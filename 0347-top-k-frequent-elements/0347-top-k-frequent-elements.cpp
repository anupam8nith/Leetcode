class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        //freq
        unordered_map<int,int> um;

        for(auto x: nums) um[x]++;

        // store
        vector<pair<int,int>> v;

        for(auto p: um) v.push_back({p.first,p.second});

        // rank

        sort(v.begin(), v.end(),[](pair<int,int> &a, pair<int,int> &b)
        {
            if(a.second==b.second) return a.first>b.first;

            return a.second>b.second;
        });
        

        vector<int> ans(k,0);

        for(int i=0;i<k;i++) ans[i]= v[i].first;

        return ans;

    }
};