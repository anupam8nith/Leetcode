#pragma GCC optimize("O3")
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
        ios_base::sync_with_stdio(false);
        unordered_map<int, int> um;
        for (auto it : arr)
            um[it]++;
        
        sort(arr.begin(), arr.end()-1, [&um](const int a, const int b)
        {
            if (um[a] == um[b])
                return a <= b;
            return um[a] < um[b];
        });
        
        if(um[arr[arr.size()-1]]==1){--k;um.erase(arr[arr.size()-1]);}
        
        for (auto it : arr)
        {
            if (um[it] > k) 
                return um.size();
            k -= um[it];
            um.erase(it);
        }
        
        
        return um.size();
    }
};