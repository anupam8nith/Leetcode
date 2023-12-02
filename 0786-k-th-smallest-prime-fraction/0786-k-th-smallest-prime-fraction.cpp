class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) 
    {
        int n = arr.size();vector<pair<int,int>> fraction;
        
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                fraction.push_back({arr[i],arr[j]});
                 fraction.push_back({arr[j],arr[i]});
            }
        
        sort(fraction.begin(),fraction.end(), [](pair<int,int> &a, pair<int,int> &b)
             {
                 double val1= a.first/(double)a.second;
                 double val2= b.first/(double)b.second;
                 
                 return val1<val2;
             });
        
        return {fraction[k-1].first,fraction[k-1].second};
    }
};