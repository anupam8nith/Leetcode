class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) 
    {
        int n = arr.size();vector<pair<int,int>> fraction;
        
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                fraction.push_back({arr[i],arr[j]});
            }
    
        sort(fraction.begin(),fraction.end(), [](pair<int,int> &a, pair<int,int> &b)
             {
                 return a.first/(double)a.second< b.first/(double)b.second;
             });
        
        return {fraction[k-1].first,fraction[k-1].second};
    }
};