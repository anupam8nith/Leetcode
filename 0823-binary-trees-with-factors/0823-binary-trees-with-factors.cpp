class Solution {
public:
    int numFactoredBinaryTrees(vector<int> &arr) 
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();long long int ans=0;

        map<int,long long int> mp;
        for(int i=0;i<n;i++)mp.insert({arr[i], 1});
        

        for(int i = 1;i<n;i++) 
        {
            auto it2 = mp.find(arr[i]);
            long long int count = 0;
            
            for(int j=0;j<i;j++) 
            {
                if(arr[i]%arr[j]==0) 
                {
                    auto it = mp.find(arr[i]/arr[j]);

                    if(it!=mp.end())
                    count = count + (it->second)*(mp.find(arr[j])->second);
                }
            }
            it2->second+=count;
        }
        
        for(auto it=mp.begin();it!=mp.end();it++)ans+=it->second;
        
        return ans%1000000007;
    }
};