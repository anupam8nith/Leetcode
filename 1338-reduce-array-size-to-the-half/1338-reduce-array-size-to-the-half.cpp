class Solution {
public:
    int minSetSize(vector<int>& arr) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int count=0;
        
        int n = arr.size(), m=n;//
        
        unordered_map<int,int> um; // hash map
        
        //store frequency of each elements
        
        for(long int i=0;i<n;i++) um[arr[i]]++;
        
        // store the frequency of elements in a new array
        
        vector<int> ans;
        
        for( auto x: um)
        ans.push_back(x.second);
        
        // sort the ans aray in descending
        
        sort(ans.begin(),ans.end(), greater<int>());
        
        // check how many elements we need to discard
        
        for(long int i=0;i<ans.size();i++)
        {
            n-=ans[i];
            count++;
            
            if(n<=m/2)
                return count;
            
        }
        
        
        
        return count;
    }
};